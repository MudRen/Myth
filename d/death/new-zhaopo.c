// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "�л�˾");
  set ("long", @LONG

�л�˾�ں���ɭɭ���������಼Χᣣ������ý���˿������Щ���
��ͼ������ǰ�����������У��������ڡ�����һ�Ź�ľ���������
����Щ���顣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north":__DIR__"new-walk2",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baiwuchang" : 1,
  __DIR__"npc/heiwuchang" : 1,
]));


  set("hell", 1);

  setup();
}

