inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥��һ��");
  set ("long", WHT@LONG
  
                ��  һ  ��



���ǡ����ϸ��¥���ĵ�һ�㣬�����İ������ﲻ����      

�ò����֣�ʱ��ʱ��������֮���д����յ���������   

�����磬�������࣬����������̧ͷ��ȥ���������컨          

�����������ϸ��������翾���... ...

LONG NOR);

  set("exits",([
   "enter" : __DIR__"qingfenglou2",
  "out" : __DIR__"qingfenglou",
//  "enter" : "/d/city/kezhan",
//   "enter" : __DIR__"woshi",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up", 1);
  setup();
}
