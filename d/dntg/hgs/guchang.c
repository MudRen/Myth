// Room: /d/4world/guchang.c
inherit ROOM;

void create ()
{
  set ("short", "�ȳ�");
  set ("long", @LONG

���ǿ����Ǳߵ�һ����ȳ������Ϻ�ƽ��ѹ�ĺ�Ӳ�����ϸ߸ߵ͵�
�м����ݶѣ����ô��������м���Ұ���ڴ��˯�������м�ֻ��ĸ
�����Ĺ����ԡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muji" : 2,
]));
  set("outdoors", "/d/4world");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"east2",
]));

  setup();
}
