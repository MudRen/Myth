// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ľ��");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"     : __DIR__"jishuigong",
  "southeast" : __DIR__"fangrigong",
  "southwest" : __DIR__"kangjingong",

]));


  set("objects", 
      ([
       __DIR__"stars/ywl" : 1,
      ]));


  setup();
}
 
