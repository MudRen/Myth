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
  "south"     : __DIR__"jingmugong",
  "southwest" : __DIR__"guijingong",
  "northwest" : __DIR__"zhangyuegong",
  "northeast" : __DIR__"weihuogong",

]));


  set("objects", 
      ([
       __DIR__"stars/lovesky" : 1,
      ]));


  setup();
}
 
