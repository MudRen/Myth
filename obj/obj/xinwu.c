//token.c
// modified 8-13-97 pickle
 
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;
#include <ansi.h>

#define SYN_CREATE  "ָ���ʽ��\tcreate <ɽ������> (<ɽ������>) for <����>��\n����\t\tcreate ˮ���� (shuilian dong) for wukong\n"

void create()
{
    set_name("��֮��", ({ "zhendong bao", "token", "bao", "zhendong" }) );
    set("unit", "��");
    set("leader_title", "����");
    seteuid(getuid());
}

string short()
{
    string guild;
 
    if( stringp(query("short")) || !stringp(guild = query("guild_name")) )
        return ::short();
    else
        return ::short();
}

string long()
{
    if( stringp(query("long")) )
        return ::long();
    else if ( stringp(query("guild_id"))) return @TEXT
����һ���Ѿ��⿪��ӡ����֮���������������ָ����������Լ���ɽ����

    modify/xiugai	�޸��������ۡ�ɽ�����Ƶȵȡ�
    assign/zhiding	��������λ�ô������ˡ�
    dismiss/jiesan	���ý�ɢ���ɽ����

TEXT
    ;
    else return @TEXT

����һ����������ҽ���ɽ��ʱ���õ���֮����
���д˱�֮�˾��Ǳ���֮������������ļ�³�Ա��
����ԭ�г�Ա���Լ����ĳ�Ա�ƺŵ�Ȩ��������
�˱����Զ����档

�ڽ����¶�֮ǰ��������һ����ʦ�����ӡ������
ѡ���һ�ζ�����create/jianli����

TEXT
    ;
}
void init()
{
    if( !environment()->is_character() ) {
	message_vision("$N����һ��ҫ�۵Ĺ�â��Ȼ����ʧ�ˡ�\n", this_object());
	destruct(this_object());
    } else {
	add_action("do_create", "create");
	add_action("do_create", "jianli");
	add_action("do_assign", "assign");
	add_action("do_assign", "zhiding");
	add_action("do_modify", "modify");
	add_action("do_modify", "xiugai");
	add_action("do_dismiss", "dismiss");
	add_action("do_dismiss", "jiesan");
    }
}

string query_autoload() { return query("guild_name"); }

string query_save_file() { return DATA_DIR + "guild/" + query("guild_id"); }

void autoload(string name)
{
    if( !restore() ) {
        if( environment() ) environment()->delete("family");
        destruct(this_object());
    }

}

int do_create(string arg)
{
    int i;
    string guild_id, guild_name, player_name;
    object me=this_player(), guild_leader;

    if( query("unsealed") )
        return notify_fail( query("name") + "�ķ�ӡ�Ѿ����⿪�ˡ�\n");
 
    if( !wizardp(me) )
        return notify_fail(
            "ֻ����ʦ�ܽ�������ӡ�������Ҫ����һ���µ�ɽ������\n"
            "����һλ��ʦ�������ˣ�����������Ϊ������ӡ��\n");
 
    if(!arg) return notify_fail(SYN_CREATE);
 
    if( sscanf(arg, "%s (%s) for %s", guild_name, guild_id, player_name)!=3)
	return notify_fail(SYN_CREATE);

    for(i=0; i<strlen(guild_id); i++)
	if( (guild_id[i] < 'a' || guild_id[i] > 'z') && guild_id[i] != '_')
        return notify_fail("<ɽ������>������СдӢ����ĸ�� '_' ��ɡ�\n");

    if (!objectp(guild_leader=present(player_name, environment(me)))
     || !living (guild_leader))
	return notify_fail("����û�� "+player_name+"��\n");

    set("guild_id", guild_id);
    set("guild_name", guild_name);
    set("unsealed", 1);
    set("leader", player_name); 

    if(file_size(query_save_file() + __SAVE_EXTENSION__)>=0 )
	restore();
    else {
	log_file("GUILD", 
	    sprintf("%s��%s����%s��%s��\n\t��"+HIG+"%s��%s��"+NOR+"��"
		    "��"+HIY+"%s��%s��"+NOR+"�ڳ�Ϊ֤��\n\n",
	    guild_leader->query("name"), guild_leader->query("id"),
	    NATURE_D->game_time(), ctime(time()),
	    guild_name, guild_id,
	    me->query("name"), me->query("id")));
	    save();
	    message_vision(HIY"��ϲ$N������"+guild_name+"("+guild_id+")��\n"NOR, guild_leader);
    }
 
    return 1;
}

int do_assign(string arg)
{
    object ob;
    mapping family;
    string assign_msg;
    object me=this_player();
 
    if( !arg || !objectp(ob = present(arg, environment(me)))
    || !living(ob) ) 
        return notify_fail("��Ҫ������֮λ����˭��\n");
 
    family = me->query("family");
 
    if( wizardp(me) || (
        mapp(family) && family["family_name"]==(string)query("guild_name")
        && (string)me->query("id")==(string)query("leader")))
    {
        // If this is a new guild, create its family.
        if( !query("leader") )
            ob->create_family(query("guild_name"));
        else {
            family = ob->query("family");
            if( !mapp(family) || (family["family_name"]!=(string)query("guild_name")) )
                return notify_fail( ob->name() + "������" + query("guild_name") + "��һԱ��\n");
        }
        ob->assign_apprentice( query("leader_title"), -1 );
        set("leader", ob->query("id"));
        if( stringp(assign_msg = query("assign_msg")) )
            message_vision(assign_msg, me, ob);
        else
            message_vision(
                "\n$N��" + query("guild_name") + "��" + query("name") + "������$n��\n"
                "\n���$p����" + query("guild_name") + "�Ķ����ˡ�\n\n", me, ob);
        move(ob);
        write("Ok.\n");
        return 1;
    } else
        return notify_fail("��û������Ȩ����\n");
}

int do_modify(string arg)
{
    string prop, str;
    if( !query("guild_id") ) return 0;
     if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
        return notify_fail("ָ���ʽ��modify <��Ŀ> <ѶϢ>\n");
    switch(prop) {
        case "name":
        case "long":
        case "short":
        case "assign_msg":
        case "leader_title":
            set(prop, str);
            save();
            write("Ok.\n");
            break;
        default:
            write("�����޸ĵ���Ŀֻ�У�name, short, long, assign_msg, leader_title��\n");
    }
    return 1;
}

int do_dismiss(string arg)
{
    if( !query("guild_id") ) return 0;
 
    rm(query_save_file() + __SAVE_EXTENSION__);
    write( query("guild_name") + "����ɢ�ˡ�\n");
    log_file("GUILD", 
        sprintf("%s��%s����%s��%s��\n\t��ɢ%s��%s����\n",
        this_player()->query("name"), this_player()->query("id"),
        NATURE_D->game_time(), ctime(time()),
        query("guild_name"), query("guild_id")));
    destruct(this_object());
    return 1;
}
