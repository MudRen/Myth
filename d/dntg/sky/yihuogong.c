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
  "south"     : __DIR__"liutugong",
  "northeast" : __DIR__"zhangyuegong",
  "southeast" : __DIR__"guijingong",
  "northwest" : __DIR__"shenshuigong",

]));


  set("objects", 
      ([
       __DIR__"stars/fire" : 1,
      ]));


  setup();
}
 
