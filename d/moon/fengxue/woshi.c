//edit by xuanzi


inherit ROOM;
#include <ansi.h>

void create()
{
  set("short","����");
  set("long" , @LONG

���������˵����ҡ������м�������Ϸ���һ¯��֪����ʲô���㣬����
��������һ�����µĸо������߷���һ��������齣��ǰ��һ����ɫ����
�硣������ʫ�ƣ�

             ������º����̴�ӡ����
             ��ˮ�����飬���½���˼

LONG);
   set("no_fight",1);
   set("no_magic",1);
   set("exits",([
     "south":__DIR__"wygdown",
     ]));
   setup();
}

void init()
{
  add_action("do_sleep","bed");
  add_action("do_sleep","gosleep");
  add_action("do_sleep","gobed");
}

int do_sleep()
{ 
    object me = this_player();
    message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n" NOR, me);
    me->move(__DIR__"wygbed");
    message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
    return 1;
}

