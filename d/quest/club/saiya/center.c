inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","�ɵ�������");
  set ("long", HIR@LONG
                    �������ɵ������ҡ�������
     �����Ƿɵ������ң��Ѿ��¾��˵��Ǳ���Ȼ�����š�
   ɢ���������Щ���������������ÿ100��������ۻ�һ�Ρ�
LONG NOR);

  set("exits",([
  "right" : __DIR__"ufo",
  "enter" : __DIR__"miroom",
  ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
set("objects", ([ /* sizeof() == 1 */
         ]));
  setup();
}
