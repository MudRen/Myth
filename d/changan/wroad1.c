// Room: /changan/wroad1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG

����·�൱���ߡ�������Զ���ǹᴩ�����ϱ��Ĵ�ٵ�����
��ֱ���������·�ϳ����٣�����һ�ӶӵĹٱ�Ѻ��һ
���������ͨ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wroad2",
  "east" : __DIR__"broadway3",
]));
  set("outdoors", 1);

  setup();
}






