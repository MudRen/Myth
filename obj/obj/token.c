// token.c

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name("��������", ({ "token" }) );
	set("unit", "��");
	set("leader_title", "������");
	seteuid(getuid());
}

string short()
{
	string guild;

	if( stringp(query("short")) || !stringp(guild = query("guild_name")) )
		return ::short();
	else
		return guild + ::short();
}

string long()
{
	if( stringp(query("long")) )
		return ::long();
	else if ( stringp(query("guild_id"))) return @TEXT
����һ���Ѿ��⿪��ӡ��������������������ָ���������������Լ�������
������֯��

    modify <��Ŀ> <�ִ�>    �޸��������ۡ��������Ƶȵ�
    assign                  ����֯�����λ�ô�������
    dismiss                 ���ý�ɢ�����֯
    
TEXT
	;
	else return @TEXT
����һ����������ҽ������ɡ����ʱ���õ������������������Ʒ���˾���
�����֯������(������)�����������ļ�³�Ա������ԭ�г�Ա���Լ����ĳ�Ա
�ƺŵ�Ȩ��������������Զ����棬�ڽ���һ������֮ǰ��������һ����ʦ���
����ʯ�ķ�ӡ(unseal)��
TEXT
	;
}

void init()
{
	if( !environment()->is_character() ) {
		message_vision("$N����һ��ҫ�۵Ĺ�â��Ȼ����ʧ�ˡ�\n", this_object());
		destruct(this_object());
	} else {
		add_action("do_unseal", "unseal");
		add_action("do_assign", "assign");
		add_action("do_modify", "modify");
		add_action("do_dismiss", "dismiss");
	}
}

string query_autoload() { return query("guild_id"); }

string query_save_file() { return DATA_DIR + "guild/" + query("guild_id"); }

void autoload(string name)
{
	if( !restore() ) {
		if( environment() ) environment()->delete("family");
		destruct(this_object());
	}
}

int do_unseal(string arg)
{
	int i;
	string guild_id, guild_name;

	if( query("guild_id") )
		return notify_fail( query("name") + "�ķ�ӡ�Ѿ����⿪�ˡ�\n");

	if( !wizardp(this_player(1)) )
		return notify_fail(
			"ֻ����ʦ�ܽ����������ķ�ӡ�������Ҫ����һ���µ����ɻ��ᣬ��\n"
			"����һλ��ʦ�������ˣ�����(��)Ϊ������ӡ��\n");

	if(!arg) 
		return notify_fail("ָ���ʽ��unseal <���ɴ���> <��������>\n");

	if( sscanf(arg, "%s %s", guild_id, guild_name)!= 2 ) {
		set("guild_id", arg);
		if( restore() ) {
			write("Ok.\n");
			return 1;
		} else {
			delete("guild_id");
			return notify_fail("û��������ɡ�\n");
		}
	}

	for(i=0; i<strlen(guild_id); i++)
		if( guild_id[i] < 'a' || guild_id[i] > 'z' )
			return notify_fail("<���ɴ���>������СдӢ����ĸ��ɡ�\n");

	set("guild_id", guild_id);
	set("guild_name", guild_name);

	if(file_size(query_save_file() + __SAVE_EXTENSION__)>=0	)
		restore();
	else {
		log_file("UNSEAL", sprintf("%s [%s] by %s, %s\n",
			guild_name, guild_id, this_player(1)->query("id"), ctime(time()) ));
	}

	write("Ok.\n");
	return 1;
}

int do_assign(string arg)
{
	object ob;
	mapping family;
	string assign_msg;

	if( !arg || !objectp(ob = present(arg, environment(this_player())))
	|| !living(ob) ) 
		return notify_fail("��Ҫ��������֮λ����˭��\n");

	family = this_player(1)->query("family");

	if( wizardp(this_player(1)) || (
		mapp(family) && family["family_name"]==(string)query("guild_name")
		&& (string)this_player(1)->query("id")==(string)query("leader"))	) {
		// If this is a new guild, create its family.
		if( !query("leader") )
			ob->create_family(query("guild_name"));
		else {
			family = ob->query("family");
			if( !mapp(family) || (family["family_name"]!=(string)query("guild_name")) )
				return notify_fail( ob->query("name") + "������" + query("guild_name") + "��һ���ӡ�\n");
		}
		ob->assign_apprentice( query("leader_title"), -1 );
		set("leader", ob->query("id"));
		if( stringp(assign_msg = query("assign_msg")) )
			message_vision( assign_msg, this_player(1), ob);
		else
			message_vision(
				"\n$N��" + query("guild_name") + "��" + query("name") + "������$n��\n"
				"\n���$p����" + query("guild_name") + "���������ˡ�\n\n", this_player(1), ob);
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
	destruct(this_object());
	return 1;
}
