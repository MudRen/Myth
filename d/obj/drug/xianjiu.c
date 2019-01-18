// by snowcat 6/1/1997
// xianjiu.c �ɾ�
// updated pickle 6-20-97

#include <ansi.h>

inherit ITEM;


void create()
{
  set_name(YEL "�ɾ�" NOR, ({"xian jiu", "jiu"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�����ϲ��е���Һ񷽬��\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  setup();
}

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                                    
  add_action("do_drink", "drink");
}


int do_drink(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

  me->set("water", (int)me->max_water_capacity());
  switch (random(3))
  {
    case 0:
    {
      message_vision(HIG "$N����һ���ɾƣ����澫���ӣ�\n" NOR, me);
      me->set("eff_gin", me->query("max_gin"));
      me->set("gin",     me->query("max_gin"));
      me->set("force",   me->query("max_force"));
      me->set("mana",    me->query("max_mana"));
    break;
    }
    case 1:
    {
      message_vision(HIG "$N����һ���ɾƣ�������ɫ���ѣ�\n" NOR, me);
      me->set("eff_kee", me->query("max_kee"));
      me->set("kee",     me->query("max_kee"));
      me->set("force",   me->query("max_force"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
    case 2:
    {
      message_vision(HIG "$N����һ���ɾƣ�������ɷ��\n" NOR, me);
      me->set("eff_sen", me->query("max_sen"));
      me->set("sen",     me->query("max_sen"));
      me->set("force",   me->query("max_force"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
  }
  destruct(this_object());
  return 1;
}
