#include <room.h>
inherit HOCKSHOP;

void create ()
{
  set ("short", "��ҵ���");
  set ("long", @LONG

���ǰ�����������һ�ҵ����ˡ�������������ƽ�ųơ��ſڹ���һ
������ (paizi)����������ϰ��Ǹ������ˣ�������Щ����׬�˲���
Ǯ��
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wu" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"north2.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ��͹ٿ�����
�������(value)���䵱(pawn)������(sell)�����(retrieve stamp)��
����(buy)  (��list�鿴)�����ֻ��ͭǮ���������ƽ���Ʊ
һ��ͨ�á�
",
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}

