// Room: /d/death/road1.c

inherit ROOM;

void create()
{
	set("short", "���Ŵ��");
	set("long", @LONG

������һ����ɭɭ��·�ϣ�ŨŨ��������������ܣ�������Զ��
����ɢȥ�Ƶġ����Ͽ�ȥ����ǿ���Էֱ��һ����¥��ģ��������
��Լ���Կ�����յ��������Ũ�����Եø���Ĺ��졣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/death/road2",
  "south" : "/d/death/gateway",
]));

	setup();
}

