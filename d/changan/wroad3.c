// Room: /changan/wroad3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG

������ȥ·�����У���ʯ·�ѿ�ʼ�����·�ˡ�ǰ������
��һ��С���㲻�ɵüӿ��˲�����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "d/gao/lu1",
  "east" : __DIR__"wroad2",
]));
  set("outdoors", 1);

  setup();
}






