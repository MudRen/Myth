// create by snowcat.c 7/18/1997

inherit ITEM;

void create ()
{
  if (random(4))
    set_name("��ٸ", ({ "bingma yong", "yong" }) );
  else
    set_name("��ٸ", ({ "bingma yong", "yong" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�����������ı���ٸ��\n");
    set("unit","��");
  }
  setup();
}

int init ()
{
  add_action ("do_act","act");
  return 1;
}

int do_act (string arg)
{
  string *msgs = ({
    "$N���ձ���ٸ����̬�Ȼ���һ�¡�\n",
    "$Nѧ�ű���ٸ����̬�����Ȼ���һ�¡�\n",
    "$N���ű���ٸ��ȫ���ע�رȻ���һ�¡�\n",
    "$Nһ�߿��ű���ٸ��һ�����űȻ���һ�¡�\n",
  });
  string *actions = ({
    "��о����Լ��ĸ��������˽�����\n",
    "����˻�������һ����ߡ�\n",
    "����˻������������µ���ߡ�\n",
    "��е�����˻���֮�����˽�����\n",
    "����˻���֮������ˡ�\n",
  });
  object me = this_player();
  object yong = this_object();

  if (arg != "yong" &&
      arg != "bingma yong")
  {
    tell_object(me,"���������Ȼ��أ�\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"���Ѿ�̫ƣ���ˣ�\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"������æ���أ�\n");
    return 1;
  }
  if (me->query_temp("weapon") ||
      me->query_temp("secondary_weapon"))
  {
    tell_object (me,"�����������޷��Ȼ���\n");
    return 1;
  }
  yong->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("unarmed",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (yong->query("times")>100)
  {
    message_vision ("ֻ��$Nҡҡ�λΣ����һ�µ��ڵ������ˡ�\n",yong);
    destruct (yong);
  }
  return 1;
}

