//Cracked by Roath
// Room: /moon/xiaolu2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

С·�쳣���С�ʱ�����ϸ�ɽ��ʱ�������ȡ�һ·������
ϡ�٣�ֻ��һЩ���㾪��ķ������ޡ�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/ourhome/npc/dog" : 1,
  "/d/lingtai/npc/youngwolf" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xiaolu3",
  "northwest" : __DIR__"xiaolu1",
]));

  setup();
}






