// Room: /d/qujing/wudidong/dong2.c

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG

��һ�����ض��죡һ������ˮ����¥�����Ŷ������֡�̨ͤ¥��
�Ŵ���أ�լ����ɽ��ǰ��ס�ľ���С��������ææ���ߡ�����
���ǳ���������������������ʱ���˳��롣ǰ�������ں������
����ֱ���󶴶�ȥ��
LONG
	);
	set("outdoors", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wdd_bedroom",
  "south" : __DIR__"dong1",
  "west" : __DIR__"kitchen",
  "north" : __DIR__"square2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
