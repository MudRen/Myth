//��ź


#include <ansi.h>

inherit ITEM;

int do_eat(string);
void destroy();
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
  call_out("destroy", 120);
}

void create()
{
  set_name(YEL "����" NOR, ({"jiao li","li"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("long", "һö���Ժ�����ɽ�������˱ǵĽ��档\n");
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
  int mana_add, force_add, howold;
  howold = (int)me->query("mud_age") + (int)me->query("age_modify");
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  mana_add = 2;
  force_add = 2;
  me->add("eat_jiaoli", 1);
  if ( (int)me->query("eat_jiaoli") > 10) {
    if( (int)me->query("maximum_force") > 100 ) {
      me->add_maximum_force(-3);
    }
    if( (int)me->query("maximum_mana") > 100 ) {
      me->add_maximum_mana(-3);
    }
    me->delete("eat_jiaoli");
    message_vision(HIG "$N����һö���棬��ɫͻȻ���䣬�����ۡ����������˳�����\n" NOR, me);
    tell_object(me,BLK "�������һ��˵������ζ������ö����ԭ�����˳��ˣ�\n" NOR);
  }
  else if( me->add_maximum_mana(mana_add) ||
    me->add_maximum_force(force_add)) {
    message_vision(HIG "$N����һö���棬���۾����Ź⣡\n" NOR, me);
  }
  else message_vision(HIG "$N����һö���棬��Ҳû������������ȥ��\n" NOR, me);
  
  if( howold > 1382400 ) {
    me->add("age_modify", -1200);
    me->add("age_modify_time", 1);
    me->add("eat/jiaoli",1);
  }
  destruct(this_object());
  return 1;
}

void destroy()
{
  destruct(this_object());
}

