//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get";

void create ()
{
	set ("short", "˯��");
	set ("long", @LONG

˯��������İ��Ŷ���ʮ����齣�����������ɫ�ı��ӡ�����
�ǳ��İ�����ż��������������д���һ������С�
LONG);

  set("no_magic",1);
	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"westway5",
	]));
        set("sleep_room",1);
        set("if_bed",1);
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
