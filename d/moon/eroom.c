//Cracked by Roath
// Room: /moon/eroom.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����¹�����ƽʱ�����ĵط�������ǽ����һ����ܡ�������鲢���࣬
�޷���һЩ�������Եķ��š�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/obj/book/san" : 1,
  "/d/obj/book/girlbook" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaoyuan",
]));

  setup();
}






