#include "ansi.h"

inherit ITEM;
int do_eat(string);
void init();

void init(){
  if (!wizardp(this_player())) {
    set("no_get","������һ�ɣ��ڵ���ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}
void create(){
    set_name( HIY "�ڵ�" NOR , ({"nei dan", "dan"}));
    set_weight(90);
    if (clonep())
      set_default_object(__FILE__);
    else {
      set("unit", "��");
      set("long", "һ�Ž��ɫ�ĵ��裬��΢���ŵ�Щ��������\n");
      set("value", 0);
       set("drug_type", "��Ʒ");
    }
    set("is_monitored",1);
    setup();
}

int do_eat(string arg){
  object me = this_player();
  if (arg!="dan" && arg!="nei dan")   return 0;

  me->add_maximum_force(random(30)); 
  me->add_maximum_mana(random(30)); 
  me->add("combat_exp",random(1000));
  message_vision(HIG "$N��������һ���ڵ��������У�һʱ���������硣
ֻ��$N���������ͨ�죬����ǳ�ʹ������ӣ�һ�����\n ������������������\n" NOR, me);
  destruct(this_object());
  return 1;
}


