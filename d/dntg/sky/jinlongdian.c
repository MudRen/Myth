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
  set ("short", "������");
  set ("long", @LONG

�����̿ɣ����ھ��ˣ�������м������������ϲ����Ž���ҫ�ճ�������
�������ݣ����ƷǷ���
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jieyindian",
]));

  setup();
}
 
