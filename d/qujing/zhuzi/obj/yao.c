// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "���",
  "�Ͷ�",
  "����",
  "�ۻ�",
  "�ƻ�",
  "��Ƥ",
  "����",
  "����",
  "�Ͼ�",
  "��ǰ",
  "����",
  "��β��",
  "����",
  "ݸ��",
  "����",
  "ţ��",
});

void create()
{
  set_name("����ҩ��ҩƷ", ({"yao", "drug"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һС��ҩ��\n");
    set("unit", "��");
    set("value", 300);
    set("no_sell", 1);
    set("food_remaining", 2);
    set("food_supply", 2);
  }
}

void init()
{
  add_action ("do_eat", "eat");
  if (query("name")=="����ҩ��ҩƷ")
  {
    set_name(names[random(sizeof(names))], ({"yao", "drug"}));
    call_out ("become_bad",600,this_object());
  }
  ::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg)
    return ::do_eat(arg);

  if (present(arg,who) == me)
  {
    if (! me->query_temp("is_ready"))
      call_out ("uncomfortable",4,who);  
  }
  return ::do_eat(arg);
}

void uncomfortable (object who)
{
  message_vision ("$N������һ���ʹ���������£�����ס������һ����\n",who);
}

varargs int move (mixed dest, int silently)
{
  mixed status;
  object where;

  status = ::move(dest,silently);
  where = environment(this_object());
  if (where && where->query("id")=="yin yaozhan")
    where->make_drug();

  return status;
}

void become_bad (object me)
{
  set_name("���ʵĻ�ҩ", ({"huai yao"}));
  me->set_temp("is_ready",0);
  me->set("value", 0);
  call_out ("destruct_me",1800,me);
}

void destruct_me (object me)
{
  destruct (me);
}

