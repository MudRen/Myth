#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "ն��̨");
  set ("long", @LONG

��ʷ�����������Ϊ��罵ħ��Ԫ˧����������ն����ĺ�Ը��
�ķ���ն��̨������һ��߶�ߵ��׭�������ķ�����ػ�����
����ɱ�����ڡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"yongdao",
  ]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/shenbing" : 2,
]));

  setup();
}


