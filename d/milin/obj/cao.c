// ���ֱ��� ������ by Calvin
#include <ansi.h>

inherit ITEM;
int do_eat(string);
void create()
{
  set_name(HIC "������" NOR, ({"hanbing cao", "cao"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ������ĺ����ݡ�\n");
    set("value", 5000);
    set("no_sell", 1);
  }

  setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N����һ�ú�����,��ʱ����ˬ���ޱȡ�\n", me);  

        me->add("bellicosity", -random( (int)me->query_kar() * 1000));
        if ((int)me->query("bellicosity") < 0 ) { 
         me->set("bellicosity", 0);
        me->add("potential", 500);
//�        me->add("mud_age",-43200);
                         }
  destruct(this_object());
  return 1;
}
