//Cracked by Roath
inherit ROOM;
#include <ansi.h>
void create ()
{
      set ("short", HIG"�ʻ���"NOR);
      set ("long", @LONG

    ������ɽ��ˮ�����Ը����ʻ���Ȼ���洦�ɼ��������Ҫ
��һЩ������ʻ���ֻҪ����λ�ϰ�����ˣ���ú�Զ�����
�ŵ�һ�������������ζ��

LONG);
        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"xw-1",
      ]));
      set("objects", ([
                     __DIR__"npc/hehua": 1,
                ]));
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
  }
