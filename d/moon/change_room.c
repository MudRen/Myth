//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��˼��");
  set ("long", @LONG

���������ʹ�������¯�е���һ�����㣬�������ơ����ط���һ�Ż����
��ʯ�󰸣����϶����������˷�������ʮ�������⣬��ɫ��Ͳ����һ����
�������һ����Ҥ���ң�����������ˮ����İ׾ջ����鰸�������ż���
��ֽ���ּ����㣬�����϶�ٰ�����֮����Ϳ��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paper" : "ֽ�Ϸ���������д��һ�仰���첻�ϣ����Ѿ�������˫˿��������ǧǧ�ᡣ
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/change.c" : 1,
  "/d/obj/flower/juhua.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huilang.c",
]));

  setup();
}
