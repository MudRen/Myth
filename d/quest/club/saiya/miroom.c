inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","��������___��������");
  set ("long", HIR@LONG




                   ��      ��       ��             
                   .     ��       ��        ��    
                   ��   �� .        ��         ��          *
      ��������������������������ȵ���ļƻ���


LONG NOR);

  set("exits",([
  "out" :__DIR__"center",
// "down" :__DIR__"9",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
        set("sleep_room",1);
        set("if_bed",1);
  set("no_clean_up", 1);
set("objects", ([ /* sizeof() == 1 */
                "/d/obj/flower/rose999" : 1,
                "/u/cigar/npc/xiaoya" : 1,
                "/d/obj/flower/hua" : 1, 
                "/u/ffff/npc2/girl": 1,
               // "/u/cigar/obj/pingpan" : 1,
        ]));
  setup();
}

