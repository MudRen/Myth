// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "����˾");
  set ("long", @LONG

����˾�ں���ɭɭ���������಼Χᣣ������ý���˿������Щ���
��ͼ������ǰ�����������У��������ڡ�����һ�Ź�ľ���������
����Щ���顣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"new-walk3",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yinchangsheng" : 1,
]));

  setup();
}

