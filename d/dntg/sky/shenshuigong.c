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
  "southeast" : __DIR__"yihuogong",
  "west"      : __DIR__"kuimugong",
  "northeast" : __DIR__"biyuegong",
  "northwest" : __DIR__"loujingong",

]));


  set("objects", 
      ([
       __DIR__"stars/hero" : 1,
      ]));


  setup();
}
 
