//ne.c
//created 4-8-97 pickle

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�칬ǽ��");
  set ("long", @LONG

    ��ò����ײ��ߵ��칬�Ķ����ǡ�������������е������쳣��
���ʣ�����Ҳ��֮��ĺܺá���ۺ����ĳ�������ͨ��������칬
�������½�һ���������ɳ�ǽ�������������ŵ����ա�������͵�ǽ
�����ԼԼ���ǹ���ķ��ܡ���������涼�ܿ���һ�����ŵ�������

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/autumn-gongcao" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"en1",
  "west" : __DIR__"ne1",
]));

  setup();
}
