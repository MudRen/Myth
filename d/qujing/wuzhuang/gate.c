//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

�����䵭�������ġ�����ת�ۼ��Ȼ�ֳ���һ��ɽ�š�ɽ����
̦ʯ�ݳɣ����ٲ����п��Կ���һ��ͨ��(bei)��ɽ��֮����¥��
���㡣
LONG);

	set("item_desc", (["bei" : "ʯ���ϴ��飺����ɽ���أ���ׯ�۶��졣\n", ]));

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"linyin2",
		"northup" : __DIR__"shaoxiang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
