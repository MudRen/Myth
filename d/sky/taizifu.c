#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "��̫�Ӹ�");
  set ("long", @LONG

���е�����������̫����߸���������̳����󽫡�������߸��
�������������к���ɱ֮����߸�ܶ����⻹ĸ���޹ǻ�����һ
�����Ʈ�������������磬���Ա�źΪ�ǣ���ҶΪ�£������
�������ԣ���߸���ֵ����������󽵷���ʮ������ħ���˵�����
ͨ���
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"yongdao",
  ]));

  set("objects", ([
    __DIR__"npc/nezha" : 1,
  ]));
  setup();
}


