// niu.c
// 1996/10/31 by none

inherit NPC;

#include <ansi.h>
#include <login.h>
#include "../honglou.h"

int do_addlist(string arg);
int set_status(mixed ob, string status);

void create()
{
	set_name("��ѩ�ʺ�", ({ "queen" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
		"�������Σ���÷��ѩ��������Σ�������˪��
�侲���Σ������չȡ��������Σ�ϼӳ������
�������Σ��������ӡ��������Σ����亮����\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "��ѩ��ػʺ���Ҳ��",
		"here" : "��ѩ֮�ϣ����֮�С�",
	]) );
	set_skill("literate", 500);
	set_skill("dodge", 500);
	set_skill("unarmed", 200);
	setup();
	carry_object("/d/ourhome/obj/pink_cloth")->wear();
}

void init()
{
	add_action("do_addlist", "addlist");
	add_action("do_getlist", "getlist");
	::init();
}

int set_status(mixed ob, string status)
{
        string uid, *member, namelist;
        int i;

//      if( geteuid(previous_object())!= ROOT_UID )
//		return 0;

        if( userp(ob) ) uid = getuid(ob);
        else if(stringp(ob)) uid = ob;
        else return 0;
        
        if( status == "(NotMember)" )
                map_delete(member_status, uid);
        else
                member_status[uid] = status;
        member = keys(member_status);
        for(namelist = "", i=0; i<sizeof(member); i++)
                namelist += member[i] + " " + member_status[member[i]] + "\n";
        rm(NL);
        write_file(NL, namelist, 1);
//        log_file( "promotion2", capitalize(uid)
//         + " become a " + status + " on " + ctime(time()) + "\n" );
        return 1;
}

int do_addlist(string arg)
{
        object ob, me;
        string old_status, new_status;
        int my_level, ob_level, level;
        string *namelist, member_name, member_level;
        int i;
	
	me = this_player();
	if ( memberhood(me)=="(NotMember)" ) {
		command("waggle " + me->query("id"));
		return 1;}

        namelist = explode(read_file(NL), "\n");
        member_status = allocate_mapping(sizeof(namelist));
        for(i=0; i<sizeof(namelist); i++) {
                if( namelist[i][0]=='#' 
                || sscanf(namelist[i], "%s %s", member_name, member_level)!=2 )
                         continue;
                member_status[member_name] = member_level;
        }

//        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
                return notify_fail("ָ���ʽ��addlist <ʹ����> <�ȼ�>\n");

        if( member_level(new_status) < 0 ) return notify_fail("û�����ֵȼ���\n");

        if( !objectp(ob = present(arg, environment(me))) 
        ||      !userp(ob) )
                return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

        if( member_level(me) < member_level(new_status) ||
		member_level(me) < member_level(ob) )
                return notify_fail("��û������Ȩ����\n");

        old_status = memberhood(ob);

        seteuid(getuid());
        if( !(set_status(ob, new_status)) )
                return notify_fail("�޸�ʧ�ܡ�\n");

        message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + " ��\n", me, ob);
        seteuid(getuid());
        ob->setup();

        return 1;
}

string *query_memberlist()
{
        string member_name, member_level, *namelist;
	int i;

        namelist = explode(read_file(NL), "\n");
        member_status = allocate_mapping(sizeof(namelist));
        for(i=0; i<sizeof(namelist); i++) {
                if( namelist[i][0]=='#' 
                || sscanf(namelist[i], "%s %s", member_name, member_level)!=2 )
                         continue;
                member_status[member_name] = member_level;
        }

	return keys(member_status);
}

int do_getlist()
{
        string *list;
	object me = this_player();

	if(memberhood(me)!="(NotMember)") {
        write(GROUP_NAME + "Ŀǰ�ĳ�Ա�У�\n");
        list = sort_array(query_memberlist(), 1);
        for(int i=0; i<sizeof(list); i++)
                printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');
        write("\n");
	}
	else {
	message_vision("�����ɹ�Ц����$N:������μӱ��\n", me);
	}
	return 1;
}

