// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//living.c

inherit ROOM;

void create ()
{
  set ("short", "��ѩ���");
  set ("long", @LONG

                ѩ���������δ�������
                Ī�������£�����ǳ��ױ

LONG);


  set("exits", ([ /* sizeof() == 4 */
   "west" : __DIR__"zoulang",
   "east" : __DIR__"restroom",
   "north" : __DIR__"meeting",
   "out" : __DIR__"fdoor",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dream":1,
  "/d/obj/flower/rose":2,
]));

  set("valid_startroom", 1);

  setup();
  "/obj/board/fxtd_b"->foo();
}


