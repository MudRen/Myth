#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "�ٵ�");
  set ("long", @LONG

  ����һ������������Ĺٵ����������ߵ��˲��࣬��Ϊ·��
�������˻������µĺۼ���
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
]));
  set("outdoors", 1);
  setup();
}