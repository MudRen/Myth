// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�һ�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"     : __DIR__"nutugong",
  "northwest" : __DIR__"niujingong",
  "southeast" : __DIR__"jishuigong",
  "southwest" : __DIR__"weiyuegong",

]));


  set("objects", 
      ([
       __DIR__"stars/lisa" : 1,
      ]));


  setup();
}
 
