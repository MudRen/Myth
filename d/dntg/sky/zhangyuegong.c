// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "���¹�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"guijingong",
  "north"     : __DIR__"zhuquedian",
  "southwest" : __DIR__"yihuogong",
  "southeast" : __DIR__"zhenshuigong",

]));


  set("objects", 
      ([
       __DIR__"stars/lady" : 1,
      ]));


  setup();
}
 
