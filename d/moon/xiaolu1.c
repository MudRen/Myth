//Cracked by Roath
// Room: /moon/xiaolu1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

С·�쳣���С�ʱ�����ϸ�ɽ��ʱ�������ȡ�һ·������ϡ�٣�ֻ��һ
Щ���㾪��ķ������ޡ�
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kunlun",
  "southeast" : __DIR__"xiaolu2",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/d/xueshan/npc/xiaozuanfeng" : 1,
]));

  setup();
}






