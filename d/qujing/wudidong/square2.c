// Room: /d/qujing/wudidong/square2.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG

���ﳱʪ���������ڹ����ֱ۴�ϸ��ţ���������������紵����
����������ǰ�治Զ�����������ڣ���֪ͨ�����Զ����ϡ���Կ�
�����ڵ����⡣�㲻�ɵļӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"houdong",
  "west" : __DIR__"guanjia.c",
  "south" : __DIR__"dong2",
  "east" : __DIR__"weaponry.c",
]));
	set("indoors", "1");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
