// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "���ޱ���");
  set ("long", @LONG

��������������£����������ľ����������޵ظ��������󶼻�
�������ܵ�Ӧ�еĴ��á���ǰһ�Ŵ����������������������Ա�
���Ŵ��й١�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"new-walk5",
  "north": __DIR__"walk1",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanluowang" : 1,
//  __DIR__"npc/panguan" : 1,
]));
  setup();
  call_other("/obj/board/shengsi_b", "???");
}
