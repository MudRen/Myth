// Room: /d/qujing/wudidong/guanjia.c

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

��ƫ����ǽ������ȴҲ����Ϊ�����ûʣ�ԭ���޵׶����ܹܾ�ס
������������ױ̨�Ϻ���ߵ㣬̨ǰ����һ�����Ů�ӣ�����
�Ծ���ױ�������ϴ�������Ũ���˱ǣ�ȴ�ڲ�ס�ⶴ�е�һ��ɧ��֮
����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"square2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tianshu" : 1,
]));
  set("outdoors", 0);

  setup();
}
