// rewritten by snowcat on 4/11/1997
// room: xiaomiao

#include <ansi.h>

#include <room.h>

inherit ROOM;

void init()
{
  add_action("do_push","push");
}

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������������������䲻������������������������Ϲ�������
ɽ�µ�ס�˻���ɽ�����ˣ�����������·��Ъ�ŵĺ�ȥ��������������
������Ъ�š�

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "����" : "������䲻�����������ƺ��ܹ��ƶ�(push)��\n",
]));

  set("exits", ([
          "northwest" : __DIR__"south2",
          "southwest" : __DIR__"south3",
       ]));

  setup();
}

int do_push(string arg)
{
  object me,tudi,where;
  int i,j;

  i = 5 + random(10);
  j = i + 3 + random(7);  

  me = this_player();
  where = environment(me);

  if(me->is_busy())
    return notify_fail("�㲻��æ����\n");

  if(!arg)
    return notify_fail("ʲô��\n");

  if(arg != "nixiang" && arg != "����")
    return notify_fail("��Ҫ��ʲô��\n");

  if(me->query("combat_exp") < 20000)
      return notify_fail("���Ǻ������������ذ���������죬һ�㶯��Ҳû�С�\n");
  if(tudi = present("tudi",where))
  {
    if(!me->query_temp("push_nixiang") || me->query_temp("push_nixiang")==0)
      return notify_fail("���ؾ�����ǰ�����������\n");
    message_vision(HIY"$Nֻ���Թ��Ե�����������С���ﳾ�����\n" NOR,me);
    me->add_temp("push_nixiang", 1);
    if((me->query_temp("push_nixiang")) > j)
    {
      message_vision("���ض�$N��Ц��һ��������һ����������󣬲����ˡ�\n",me);
      destruct(tudi);
      me->set_temp("qi_zou_tu_di",1);
    }
    return 1;
  }
  else
  {
    if(me->query_temp("qi_zou_tu_di"))
      return notify_fail("�����ȥ��������������û������\n");
    me->add_temp("push_nixiang", 1);
    if(me->query_temp("push_nixiang") < i)
    {
      message_vision("\n$N���������������ƻ��˻Ρ�\n"NOR,me);
      return 1;
    } 
    if(!me->query_temp("called_tudi"))
    {
      message_vision(HIR"�����Ȼ���ҵ�ҡ��ҡ���������ΡΡ�شӺ������˳�����\n"NOR,me);
      tudi = new (__DIR__"npc/tudi");
      tudi->move(where);
      me->set_temp("called_tudi");
    }
    return 1;
  }
}


int valid_leave(object me, string dir)
{
  me->delete_temp("push_nixiang");
  call_out("peace", 300,me);
  return ::valid_leave(me, dir);
}

void peace(object me)
{
  if (me)
    me->delete_temp("qi_zou_tu_di");
}
