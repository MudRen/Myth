// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "���¹�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"     : __DIR__"baihudian",
  "west"     : __DIR__"loujingong",
  "southwest" : __DIR__"shenshuigong",
  "northwest" : __DIR__"bihuogong",

]));


  set("objects", 
      ([
       __DIR__"stars/lwq" : 1,
      ]));


  setup();
}
 
