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
  set ("short", "�ʺ���");
  set ("long", @LONG

���м������ţ����Ͽ��ż�����ɫ�ʺ硣����������ʮ�����칬��
��ǲ�ƹ�����ɳ������������̫��������ҩ��������һ��������
�����ޣ�������ʮ���ر���˳���������������
���ٵ���� һ������������롣

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jieyindian",
  "north" : __DIR__"xingrigong",
]));

  setup();
}
 
