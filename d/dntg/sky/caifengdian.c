// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "�ʷ��");
  set ("long", @LONG

�����̿ɣ����ھ��ˣ�������м���������յ������ϼ�ϻ�
ӳ��⣬���������ڶ��ڡ�

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jieyindian",
]));

  setup();
}
 
