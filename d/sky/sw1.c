//sw1.c
//created 4-8-97 pickle

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�칬ǽ��");
  set ("long", @LONG

    ������������е������쳣�����ʣ�����Ҳ��֮��ĺܺá�����
���칬�ĸ�ǽ����ۺ����ĳ�������ͨ��������칬�������½��
�������ɳ�ǽ�������������ŵ����ա�������͵�ǽ�����ԼԼ��
�ǹ���ķ��ܡ�����ңң���Կ��������š�

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sw",
  "east" : __DIR__"nantian",
]));
  set("outdoors", 1);

  setup();
}
