// by Repoo
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIR"����֮���ſ�"NOR);
  set ("long", @LONG
  
  һ�������Ĺ㳡�м�������һ�����ϵ��������п��ҡ�
���飺����֮���䲻ʱ�й����������

��������ܶ����ϱ��������������һ��һ�١������˹��졣
��������ڹ㳡�м�����Ӧ���ǿ��Խ�ȥ�ġ�
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
    //  "enter" : __DIR__"shendian",
]));
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
void init()
{
        add_action("do_enter", "enter");
        set("no_clean_up", 1);
}

int do_enter()
{
        object me;
        me=this_player();

  if(me->query_temp("fahua/read") == "done")
   {
   me->move("/d/shendian/shendian");
    return 1;
   }
     else
    {
                 return notify_fail("������ô��������ģ�\n");
   }
}
