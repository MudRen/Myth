 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ص����");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"     : __DIR__"weihuogong",
  "northeast" : __DIR__"fangrigong",
  "northwest" : __DIR__"kangjingong",

]));


  set("objects", 
      ([
       __DIR__"stars/matthew" : 1,
      ]));


  setup();
}
 
