inherit ROOM; 
#include <ansi.h> 
void leave_here(object me);

void create ()
{
  set ("short", "��ľ��");
  set ("long", HIG @LONG
���涼���İ������֣����ﻨ�������䣬ʵ���Ǿ����ķ羰��
Ȼ����û��ʲô����ָʾ�뿪��ȥ��Ҳû��ʲô�ܰ�ʾ��������
�
LONG);

  set("exits", ([
        "east"      : __DIR__"spirit3",
        "west"      : __DIR__"spirit3",
        "south"     : __DIR__"spirit3",
        "north"     : __DIR__"spirit3",
        "northwest" : __DIR__"spirit3",
        "southwest" : __DIR__"spirit3",
      ]));
  set("valid_startroom",1);
  setup();
}

void init()
{
  add_action("do_quit", "quit");
}

int do_quit ()
{
  object me;
  me = this_player();

  me->set("startroom",base_name(environment(me)));
  tell_object(me,"��ʱ�뿪��ľ�󡭡�\n");
  return 0; // return 0 to invoke normal quit
}

int valid_leave (object me, string dir)
{
  int i;

  me->set("startroom",base_name(environment(me)));
  if (i = me->query_temp("out_of_greenyard"))
  {
    i++;
    me->set_temp("out_of_greenyard",i);
    if (i > 5)
    {
      me->set_temp("lost_in_greenyard",0);
      me->set_temp("out_of_greenyard",0);
      
      call_out("leave_here",1,me);

      return 1;
    }
  }
  else if (! me->query_temp("lost_in_greenyard"))
  {
    me->set_temp("lost_in_greenyard",1);
    call_out("found_outlet",240+random(240),me);
  }
  return 1;
}

// mon move this out of the valid_leave function
// to prevent an Illegal move error.
// 4/11/98
void leave_here(object me)
{
     object cao;      me->move(__DIR__"outlet");
      if (! present("icedew",environment(me)))
      {
        cao = new("/d/quest/tulong/obj/xiaocao");
        cao->move(environment(me));
      }
      tell_object(me,HIG"�̲ݵ�����һ�仨��\n"NOR);
}

void found_outlet(object me)
{
  if(!me) return;
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",1);
}


