 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "θ����");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"      : __DIR__"bihuogong",
  "southwest" : __DIR__"angrigong",
  "southeast" : __DIR__"loujingong",

]));


  set("objects", 
      ([
       __DIR__"stars/abai" : 1,
      ]));


  setup();
}
 
