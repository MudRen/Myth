inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���Ƿɵ�");
  set ("long", HIR@LONG
                           ����    ��  ��  ��  ��    ����

    �������������������ڵ����ϵ�һ���ɵ����ɵ��ڶ������ƾɵ���������ǽ��һ��ˮ����
��Ȼ������˿���⣬�ƺ��Ծɿ��Ժ�ĳ�����صĿռ�������硣�
    �������һ�ȷ����ţ��ұ���һ���İ���ͨ����    

LONG NOR);

  set("exits",([ 
  "left" : __DIR__"center", 
  "right" : __DIR__"tunnel",
]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 1);
  set("no_clean_up", 1);
  setup();
}

