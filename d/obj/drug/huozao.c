//��ź


#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(RED "����" NOR, ({"huo zao","zao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("long", "һö���Ժ�����ɽ��ɫ���������档\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  
  // the following line is added by snowcat
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  int mana_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
	mana_add = 2+random(2);
  me->add("eat_huozao", 1);
  if ( (int)me->query("eat_huozao") > 10) {
    if( (int)me->query("maximum_mana") > 100 ) {
      me->add_maximum_mana(-5);
    }
    me->delete("eat_huozao");
    message_vision(HIG "$N����һö���棬��ɫͻȻת�̣������ۡ����������˳�����\n" NOR, me);
    tell_object(me,BLK "ԭ����ö���껵�棡\n" NOR);
  }
  else if( me->add_maximum_mana(mana_add)){
    message_vision(HIG "$N����һö���棬��ɫ�����ͬ�һ�һ��ͨ�죡\n" NOR, me);
  }
  else message_vision(HIG "$N����һö���棬��ɫͻȻת�죬������òŵ�����ȥ��\n" NOR, me);
  if( howold > 1382400 ) {
    me->add("age_modify", -1200);
    me->add("age_modify_time", 1);
  }
  
  destruct(this_object());
  return 1;
}

