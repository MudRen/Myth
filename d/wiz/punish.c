// Room: /d/wiz/punish.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG

����������������ϣ���Ѿ���С�ˡ�
LONG
	);
	
	set("valid_startroom", 1);

	setup();
	
}

void init()
{   
	if (!wizardp(this_player())) {
          this_player()->set("startroom","/d/wiz/punish");
	  this_player()->save();
	  add_action("block_cmd","",1);   	
	}
	call_out("hehe", 2, this_player());
}

int block_cmd()
{
        string verb = query_verb();
	
        if (verb=="say") return 0; //allow say
	if (verb=="help") return 0;
	if (verb=="look") return 0;
	return 1;
}
/*
// added by bula, just for fun.

void hehe()
{
        tell_room(environment(this_player()), "\n"+
		"���ڵ��η��ﴫ������ҽ�����\n"+
		"������ԼԼ���������η������˴󺰣����л��ǲ��У�\n"+
		"���ڵ��η��ﴫ������Ƥ������\n"+
		"������ԼԼ���������η������˺��������ǵ�������̹�״ӿ����ܴ��ϣ�\n"+
		"������ԼԼ��������˵�������������������\n"+
		"���ڵ��η�������Ц��������Щ���ˣ��Ͳ��س���ٱ����ˣ�\n");
        return;
}

*/
