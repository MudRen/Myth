// Room: /d/quest/newtask/jiuyouju
//created by kuku@sjsh 2002/11

inherit ROOM;
#include <room.h>

void create ()
{
          set ("short", "���ľ�");
          set ("long", @LONG

�����Ǿ����������ӵĵط���������С��
ȴ���쳣�ɾ����ࡣ

LONG);

          set("objects", ([ /* sizeof() == 1 */
                  __DIR__"npc/jiuyou" : 1,
          ]));
          set("exits", ([ /* sizeof() == 2 */
                  "north" : "/d/changan/wside2",
          ]));

          create_door("north", "��ľ��", "south", DOOR_CLOSED);
          setup();
}
