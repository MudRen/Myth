// ���ֱ��� Ѫ���� by Calvin
#include <ansi.h>

inherit ITEM;
int do_eat(string);
void create()
{
  set_name(HIR "Ѫ����" NOR, ({"xue puti", "puti"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("long", "һֻ����Ѫ���ᡣ\n");
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

        message_vision("$N����һֻѪ�����ʱ��Ͼ����,Ѫ�����ǡ�\n", me);  

        me->add("bellicosity", random( (int)me->query_kar() * 50));
        if ((int)me->query("bellicosity") < 0 ) { 
        me->add("bellicosity", 0);
        me->add("potential", 1000);
                         }
  destruct(this_object());
  return 1;
}
