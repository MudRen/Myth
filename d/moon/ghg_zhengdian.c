//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�㺮������");
  set ("long", @LONG

ӭ���ȿ���һ����������ش��ң�����д�����������֣����㺮������
����̴��󤰸�����������������̹Ŷ���������©�泯ī���󻭣�һ����
��׶�ͣ�һ���ǲ����У���������ʮ������̴���Ρ�������
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fairy2.c" : 1,
  __DIR__"npc/fairy3.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"wulang.c",
  "south" : __DIR__"road3",
  "west" : __DIR__"huilang.c",
]));

  setup();
}
