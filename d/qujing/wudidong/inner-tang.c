// Room: /d/qujing/wudidong/inner-tang.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

���������С�����ر��ߣ�����׼������ϯ��һ��Ů�����и�����
���ٵʹ������ΰ����Ц������ָ������С����ȫ�����Լ��㺹��
�졣������Ⱥ��һ�죬һʱ��Ҳ���˷�����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushu" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tang-gate",
]));

  setup();
}
