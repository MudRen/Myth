//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

һ�䲻��ķ���,����������ĵ��ߺ�һЩ�ճ����þߡ�
LONG);

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/daoyaochu" : 1,
  __DIR__"obj/bigaxe" : 2,
  "/d/obj/weapon/whip/wuchou":2,
  __DIR__"obj/snow_sword" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"courtyard.c",
  "south" : __DIR__"wulang.c",
]));

  setup();
}
