
// Room: /d/death/block.c
inherit ROOM;


void create ()
{
	set ("short", "����֮��"); 
	set ("long", @LONG

ʫԻ��
	����δ������ң�ãã�������˼���
	�Դ��̹��ƺ��ɣ����ٴ������Ǳ档

�̹ſ��죬����׻�����ϧ���������������ã����֮�⣬�޴����
֮���ˡ�����һ�����δ�𣬸Ͻ�Ͷ̥(suicide/reborn)�ɡ�

LONG);

	set("valid_startroom",1);

	setup();
}

void init()
{
	if( !wizardp(this_player()) )   
	{
		this_player()->set("startroom", "/d/death/block");
		add_action("block_cmd", "", 1);
	}   
}

int block_cmd(string args)
{
	string verb;
   
	verb = query_verb();
	if(verb == "quit" || verb == "look" || verb == "suicide") return 0;
   
	return 1;
}


