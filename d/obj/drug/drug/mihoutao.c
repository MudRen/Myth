// mihoutao.c ⨺���

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void destroy();
void init();

void init()
{
  if (!wizardp(this_player())) {
//   set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
  call_out("destroy", 120);
}

void create()
{
  set_name(YEL "⨺���" NOR, ({"mihou tao","mihoutao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�Ƴȳȵ�һ��⨺��ң�����˴������Ρ�\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(1);
  me->add_maximum_mana(1);
  message_vision(HIG "$N����һ���ֺ��ң��̲�סץ�����������˵�ֱ�뷭��ͷ�� \n" NOR, me);
  
  destruct(this_object());
  return 1;
}

void destroy()
{
  destruct(this_object());
}
