
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "Ժ��");
  set ("long", @LONG
        
     ��������������ɽ֮�ۣ�����;����������ȣ�Ҳ��
������κ�ΰ��ɽ���ƾɣ��������ʧ�ޡ�
LONG);

  set("outdoors", "/u/dragon/kfadd/door");
  set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"neitang",
  "out" : __DIR__"door",
  ]));

create_door("out", "ʯ��", "enter", DOOR_CLOSED);
  setup();
}
