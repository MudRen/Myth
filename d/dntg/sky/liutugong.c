 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"     : __DIR__"yihuogong",
  "southeast" : __DIR__"xingrigong",
  "northeast" : __DIR__"guijingong",

]));


  set("objects", 
      ([
       __DIR__"stars/feixiao" : 1,
      ]));


  setup();
}
 
