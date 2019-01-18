// neidan.c �����ڵ�

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIM "�����ڵ�" NOR, ({"chunyang neidan","neidan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "������ʦ�������İ��깦�����ɵ��ڵ���\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  int force_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
    force_add = 60+random(30);
  me->add("eat_neidan", 1);
  if( (int)me->query("eat_neidan") > 10) {
  if( (int)me->query("maximum_force") > 100 ) {
    me->add_maximum_force(-5);
    }
    me->delete("eat_neidan");
    message_vision(HIM"$N��û�������������ڵ������������ڵ����İ����ھ������õ����͵����ܡ�\n" NOR, me);
    tell_object(me,BLK"��������һ����$N��Ϣ��ת���³�һ����Ѫ��\n" NOR);
  }
  else if( me->add_maximum_force(force_add)){
    message_vision(HIM "$N����һ���ڵ���ֻ��Ѫ�����ڣ��泩�ޱȣ��̲�ס��У��óԣ���Ҫ��\n" NOR, me);
  }
  else message_vision(HIM "$N����һ���ڵ�����ɫͻȻת�죬������òŵ�����ȥ��\n" NOR, me);
  if( howold > 1382400 ) {
    me->add("mud_age", -43200);
    me->add("mud_age_time", 1);
  }
  
  destruct(this_object());
  return 1;
}

