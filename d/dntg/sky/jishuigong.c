// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ˮ��");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"     : __DIR__"jiaomugong",
  "southeast" : __DIR__"kangjingong",
  "southwest" : __DIR__"xinyuegong",
  "northwest" : __DIR__"shihuogong",

]));


  set("objects", 
      ([
       __DIR__"stars/taiping" : 1,
      ]));


  setup();
}
 
