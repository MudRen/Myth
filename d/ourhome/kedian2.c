// Room: /city/kedian2.c

inherit ROOM;

void create ()
{
  set ("short", "�Ľ�Ұ��");
  set ("long", @LONG
�������ڻĽ�Ұ���һ�����С·�ϣ�ֻ��һЩС����
�����������ȥ�� 
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian",
  "south" : __DIR__"kedian3",
]));
              set("no_magic", 1); 
        set("no_fight",1);
        set("objects", ([ /* sizeof() == 1 */
  "/obj/money/silver" : 2,
]));

  setup();
}
