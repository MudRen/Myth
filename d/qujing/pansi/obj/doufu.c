// by snowcat 11/20/1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�嶹��", ({"jian doufu", "doufu", "fu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��������ƵĶ�����ɢ������ֵ���ζ��\n");
    set("unit", "��");
    set("value", 300);
    set("food_remaining", 4);
    set("food_supply", 50);
  }
}

void init ()
{
  add_action ("do_eat", "eat");
}

int do_eat (string arg)
{
  object who = this_player();
  object me = this_object();
  object ob = present (arg,who);

  if (ob != me)
    return 0;

  remove_call_out ("reacting");
  call_out ("reacting",2+random(4),who);    
  return ::do_eat(arg);
}

void reacting (object who)
{
  if (! who)
    return;

  message_vision("$Nһ���Ӷ��ģ������³�����\n",who);
}
