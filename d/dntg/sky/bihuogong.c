// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"      : __DIR__"weitugong",
  "northeast" : __DIR__"bishuigong",
  "southwest" : __DIR__"loujingong",
  "southeast" : __DIR__"biyuegong",

]));


  set("objects", 
      ([
       __DIR__"stars/near" : 1,
      ]));


  setup();
}
 
