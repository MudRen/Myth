// create by snowcat.c 7/18/1997

inherit ITEM;

void create ()
{
  set_name("ʯ��", ({ "shi gui", "gui" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "һֻ������ʯ����ǧ��ʯ�ꡣ\n");
    set("unit","ֻ");
  }
  setup();
}

int init ()
{
  add_action ("do_touch","touch");
  return 1;
}

int do_touch (string arg)
{
  string *msgs = ({
    "$N����ָ���ʯ�ꡣ\n",
    "$N�����ؽ��ַ���ʯ���ϡ�\n",
    "$N��ϸ�����ֻ�������ʯ�ꡣ\n",
    "$N��Ĭ�ظ�����ʯ�ꡣ\n",
  });
  string *actions = ({
    "��о�ʯ������ԼԼ������һ��������\n",
    "��·����ʯ��ɢ����һ�����ε�������\n",
    "���ƺ��о���ʯ�꽫ĳһ��˵���������������㡣\n",
    "���㱵ظ��ܵ�ʯ���������\n",
    "�ƺ���һ�ֹ������ص���������������ڡ�\n",
  });
  object me = this_player();
  object gui = this_object();

  if (arg != "gui" &&
      arg != "shi gui")
  {
    tell_object(me,"��Ҫ����ʲô��\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"���Ѿ�û�������ˣ�\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"������æ���أ�\n");
    return 1;
  }
  gui->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("force",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (gui->query("times")>300)
  {
    message_vision ("ֻ��$N���������°ɵ�������"+
                    "ͻȻ���ѳ�������ʯ��ɢ���ڵء�\n",gui);
    destruct (gui);
  }
  return 1;
}

