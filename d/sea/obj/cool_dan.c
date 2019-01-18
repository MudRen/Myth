#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "��ˮ��" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�����͵�һ�ű�ˮ����\n");
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

	message_vision(HIC"$N����һ�ű�ˮ������ɫ���һƬ�Ұס�\n"NOR, me);  
  
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
	me->add("potential", 100);

  destruct(this_object());
  return 1;
}
