// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ţ��");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"     : __DIR__"xurigong",
  "south"     : __DIR__"weiyuegong",
  "southeast" : __DIR__"shihuogong",
  "southwest" : __DIR__"bishuigong",
  "northwest" : __DIR__"doumugong",
  "northeast" : __DIR__"nutugong",

]));


  set("objects", 
      ([
       __DIR__"stars/wugeng" : 1,
      ]));


  setup();
}
 
