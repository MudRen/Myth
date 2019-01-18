inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ԡ��");
  set ("long", HIR@LONG

    һ���������ڵİ���������Χס���㼸����ԡ����˯���ˡ��ʻ�Ư��
�����Ѿ�ɫ��ԡҺ�У�����ǿ����ˮ����Ħ�������Ƥ����
    ���ֱ����Ĳ�Ը������ˡ�
    �������ǿ���˸��������
LONG NOR);

  set("exits", ([
        "up"     : __DIR__"woshi",
      ]));
  set("objects", ([ /* sizeof() == 1 */
     //  __DIR__"npc/girl" : 2,
      ]));
  set("resource", ([ /* sizeof() == 1 */
    "spring" : 1,
      ]));

  set("outdoors", __DIR__);

  setup();
}

int init ()
{
  add_action ("do_bath","bath");
  add_action ("do_cure","cure");
  return 1;
}

int do_bath (string arg)
{
  string *msgs = ({
    "$N��ԡˮ��ϴ��������\n",
    "$N��ԡˮϴ��ϴ�Լ���\n",
    "$N��ԡˮ���������ڵ�ϴ��������\n",
    "$N�����ȵ�ԡˮϴ��ϴ�Լ���\n",
  });
  string *actions = ({
    "��о���ԡˮ��һ��˵�������ĵ�������\n",
    "��·����ԡˮ��һ�����صķ�����������������ڡ�\n",
    "���ƺ��о�����һ�������������ڡ�\n",
    "���㱾�����һ�����صķ����������֡�\n",
    "�ƺ���һ�����صķ�������������ڡ�\n",
  });
  object me = this_player();

  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"��̫�����ˣ�ϴ��ˮԡ��Σ�գ�\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
    return notify_fail ("������ԡ����æ���أ�\n");
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("spells",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  return 1;
}

int do_cure (string arg)
{
  string *msgs = ({
    "$N����ԡˮ�����������ؽ�������\n",
    "$N��ԡ��ʹ�������Լ����ϴ��š�\n",
    "$NҨ�����ȵ�ԡˮ�������Ͻ�������\n",
    "$N�����Ӵ��ԡ���У������Լ������塣\n",
    "$N�����������ڵ�ԡ�ס�\n",
    "$N����ԡ���У���������ԡ��\n",
  });
  object me = this_player();

  if (me->is_busy())
    return notify_fail ("������ԡ����æ���أ�\n");
  message_vision (msgs[random(sizeof(msgs))],me);
  me->start_busy(1,1);
  if ((me->query("kar")+me->query_temp("spring/cure_times")) > 60)
  {
    if (! me->update_condition())
      return 1;
    message_vision ("$N��������վ��������������ԡ�����ϡ�\n",me);
    me->clear_condition();
    me->unconcious();
  }
  me->add_temp("spring/cure_times",1);
  return 1;
}

int valid_leave(object me, string dir)
{
  me->delete_temp("spring/cure_times",1);
  return ::valid_leave(me, dir);
}

