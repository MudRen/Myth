// Room: /d/jjf/guest_cabinet2.c

inherit ROOM;

void create ()
{
  set ("short", "�����¥");
  set ("long", @LONG

����Է���Ϊ���ʣ�����һ����̴ľ�󰸣��ķ��ı��뱸������һ��
СС�辰�����ⰻȻ��ת�����磬ӭ��ֻ��һ��д��ɽˮ�������ݺᡣ
�Ա߾�����齣�����ˮ��ɴ�ʣ�����Щ����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luocheng.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guest_shufang",
  "down" : __DIR__"guest_cabinet",
]));
  set("if_bed", 1);
  set("sleep_room", 1);

  setup();
}
