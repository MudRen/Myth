// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "ƽ�ȵ�");
  set ("long", @LONG

�����������ظ�ʮ��֮ƽ�����Ĺ��ƽʱ�������£�ƽ��
������ڵ��ϴ���һЩ���񣮵���һ�Ŵ�ľ�������϶���һЩ
�ĸ�֮�࣬һ��С��ͭ¯���ŵ����ĵ����̣�һ������ͯ����
���ں�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"walk3",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/pingdengwang" : 1,
  __DIR__"npc/tong" : 1,
]));

  setup();
}
