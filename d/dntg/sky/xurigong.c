// Room: /d/sky/nantianmen
 
#include <ansi.h>
inherit ROOM;

void init();

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
  "south"     : __DIR__"niujingong",
  "north"     : __DIR__"caihongqiao2",
  "southeast" : __DIR__"nutugong",
  "southwest" : __DIR__"doumugong",

]));


  set("objects", 
      ([
       __DIR__"stars/fer" : 1,
      ]));


  setup();
}
 
