// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "���ٵ�");
  set ("long", @LONG

�����������ظ�ʮ��֮�������Ĺ��ƽʱ�������£�����
������ڵ��ϴ���һЩ���񣮵���һ�Ŵ�ľ�������϶���һЩ
�ĸ�֮�࣬һ��С��ͭ¯���ŵ����ĵ����̣�һ������ͯ����
���ں�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"walk3",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/chuguanwang" : 1,
  __DIR__"npc/tong" : 1,
]));

  setup();
}
