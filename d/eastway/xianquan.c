// create by snowcat.c 4/20/1997
// room: /d/eastway/xianquan.c

inherit ROOM;

void create ()
{
  set ("short", "��Ȫ");
  set ("long", @LONG

һ���������ڵİ���������Χס�����Ѿ���������Ȫ�ߡ�Ȫ��
��ˮ�̲�������ˮ���������ƣ�����������������Ŀ��ԡ��
LONG);

  set("exits", ([
        "out"     : __DIR__"huaqing",
      ]));
  set("objects", ([ /* sizeof() == 1 */
      __DIR__"npc/girl" : 2,
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
    "$N��Ȫ��ϴ��������\n",
    "$N��Ȫˮϴ��ϴ�Լ���\n",
    "$N��Ȫ���������ڵ�ϴ��������\n",
    "$N�����ȵ�Ȫˮϴ��ϴ�Լ���\n",
  });
  string *actions = ({
    "��о���Ȫˮ��һ��˵�������ĵ�������\n",
    "��·����Ȫˮ��һ�����صķ�����������������ڡ�\n",
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
    return notify_fail ("��������Ȫ��æ���أ�\n");
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
    "$N����Ȫˮ�����������ؽ�������\n",
    "$N����Ȫˮ���Լ�����һ����\n",
    "$NҨ�����ȵ�Ȫˮ�������Ͻ�������\n",
    "$N������Ȫˮ�У������Լ������塣\n",
    "$N�����������ڵ�Ȫˮ��\n",
    "$N������Ȫˮ�У���������ԡ��\n",
  });
  object me = this_player();

  if (me->is_busy())
    return notify_fail ("��������Ȫ��æ���أ�\n");
  message_vision (msgs[random(sizeof(msgs))],me);
  me->start_busy(1,1);
  if ((me->query("kar")+me->query_temp("spring/cure_times")) > 60)
  {
    if (! me->update_condition())
      return 1;
    message_vision ("$N��������վ���������ߵ�Ȫ�ߡ�\n",me);
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
