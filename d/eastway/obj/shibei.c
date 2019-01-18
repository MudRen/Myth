// create by snowcat.c 7/18/1997

inherit ITEM;

void create ()
{
  set_name("ʯ��", ({ "shi bei", "bei" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "һ��������ĵľ޴�ʯ����\n");
    set("unit","��");
  }
  setup();
}

int init ()
{
  add_action ("do_examine","examine");
  return 1;
}

int do_examine (string arg)
{
  string *msgs = ({
    "$N��ס������ϸ�ع۲���ʯ����\n",
    "$Nȫ���ע���Ķ����ġ�\n",
    "$Nϸ�ĵز쿴���ġ�\n",
    "$Nһ���о����ģ�һ��˼����\n",
  });
  string *actions = ({
    "����еõ�һЩ������\n",
    "��Ա��������˽�һ������⡣\n",
    "����öԱ����ƺ����˸������⡣\n",
    "���ʱ�е�����һЩ�µ��ջ�\n",
    "��ӱ����л����һЩ֪ʶ��\n",
  });
  object me = this_player();
  object bei = this_object();

  if (arg != "bei" &&
      arg != "shi bei")
  {
    tell_object(me,"��Ҫ�о�ʲô��\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"����Ҳû�о���ȥ�о������ˣ�\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"������æ���أ�\n");
    return 1;
  }
  bei->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("literate",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (bei->query("times")>200)
  {
    message_vision ("ֻ��$N����һ�£�"+
                    "����һ��������ʯ���С�\n",bei);
    destruct (bei);
  }
  return 1;
}

