 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "β��");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"     : __DIR__"ditugong",
  "southwest" : __DIR__"zhenshuigong",
  "northeast" : __DIR__"kangjingong",
  "northwest" : __DIR__"xinyuegong",

]));


  set("objects", 
      ([
       __DIR__"stars/liz" : 1,
      ]));


  setup();
}
 
