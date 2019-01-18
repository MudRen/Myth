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
  set ("short", "���չ�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"caihongqiao",
  "north"     : __DIR__"guijingong",
  "northwest" : __DIR__"liutugong",
  "northeast"      : __DIR__"jingmugong",

]));


  set("objects", 
      ([
       __DIR__"stars/glads" : 1,
      ]));


  setup();
}
 
