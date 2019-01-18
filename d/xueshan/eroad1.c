//standroom.c used by weiqi...others may hate this format:D
//eroad1.c

inherit ROOM;

void create ()
{
	set ("short", "���µ�");
	set ("long", @LONG

�����Ǳ��µ��¡������б�ĵط������ϴ�ݲ���������ȴ�ӱ�
�����������С��(xiaocao)�����ֲ�Ҷ��Բ��ɫ������������
��������������ؿẮ�����������ӡ�������ȥ���Լ���һ����
���Сľ����������������ڱ�ѩӳ�����������⡣
LONG);

	set("item_desc", (["xiaocao" : "���ֲ�Ҷ��Բ��ɫ����������ȷ�ÿ��� \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"***",
		//"north" : __DIR__"icegate",
		"west" : __DIR__"xuelu",
		"east" : __DIR__"eroad2",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/ice" : 2,
	]));


	set("outdoors", "xueshan");

	set("no_xiaocao", 0);

	setup();
}

void init()
{
	add_action("do_dig", "dig");
	add_action("do_dig", "wa");
}

int do_dig(string arg)
{

	object ob, me;
	
	me=this_player();

	if( (!arg) || (arg != "xiao cao" && arg != "xiaocao" && arg != "cao" && arg !="С��") )
		return notify_fail("��Ҫ��ʲô��\n");

	if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) ) 
		return notify_fail("���Ҹ��ù��߰ɡ�\n");

	if (query("no_xiaocao"))
		return notify_fail("û�����ˣ����ڿ�ȸ�����������㲻�ɡ�\n");

	ob=new("/d/obj/misc/xiaocao");
        	ob->move(me);
	message_vision("$N�ڳ�һ����ɫС�ݣ�С������زص��˻��\n", me);
	set("no_xiaocao", 1);
	call_out("regenerate", 300);
	return 1;
}

int regenerate()
{
	set("no_xiaocao", 0);
	return 1;
}


