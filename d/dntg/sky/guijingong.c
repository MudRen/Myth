// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"xingrigong",
  "north"     : __DIR__"zhangyuegong",
  "southwest" : __DIR__"liutugong",
  "southeast" : __DIR__"jingmugong",
  "northwest" : __DIR__"yihuogong",
  "northeast" : __DIR__"zhenshuigong",

]));


  set("objects", 
      ([
       __DIR__"stars/amao" : 1,
      ]));


  setup();
}
 
