// Room: /d/moon/fengxue/wytdamen
//edit by xuanzi

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIG"����¥��"NOR);
  set ("long", @LONG

����һ���ľ���¥�󣬴����϶�������ɫ�Ĵ�ɴ����Χ������������ɢ
���ŵ��������㡣���������ţ�������ǰ����һ��СС��ɴ�������飺

                        ����Ī��

LONG);

  set("outdoors", __DIR__);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"xiaolu",
  "enter" : __DIR__"wygdown",
  "north":__DIR__"huayuan",
]));

  setup();
}

int valid_leave(object me, string dir)
{
   string myid=this_player()->query("id");
   if (!(myid=="xqls"))
  {
     if (!me->query_temp("wxt_invited") && dir=="enter")
     {
       return notify_fail("����ط�������Ҫ���˵�������ܽ�ȥҮ����������(@_@)\n");
     }
  }
  return ::valid_leave(me,dir);
}

void init()
{
  add_action("do_invit","invit");
}

int do_invit(string arg)
{
  object me=this_player(), obj;

  if (me->query("id")!="xqls")
    return notify_fail("ʲô��\n");

  if (!arg)
    return notify_fail("��Ҫ����˭����\n");

  if(!objectp(obj = present(arg, environment(me))))
     return notify_fail("����û������ˡ�\n");

  if( !obj->is_character() || obj->is_corpse() )
     return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

   message_vision("$N��$n˵������ӭ"+RANK_D->query_respect(obj)
        +"�����¸��棡 \n", me, obj);
  
  obj->set_temp("wxt_invited",1);

  return 1;
}

