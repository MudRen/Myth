// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "Σ�¹�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"xianwudian",
  "north"     : __DIR__"niujingong",
  "northeast" : __DIR__"shihuogong",
  "northwest" : __DIR__"bishuigong",

]));


  set("objects", 
      ([
       __DIR__"stars/erica" : 1,
      ]));


  setup();
}
 
