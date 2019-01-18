// Created by waiwai@2000/09/16

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"������ָ�们�䣡\n");
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_put","��ô����Ķ���������߬��ѽ����԰ɣ����ˣ�\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
//    call_out("self_dest",3600+random(60),this_object());
//    remove_call_out("announce");
//    call_out("announce",random(60),this_player());

}

void create()
{
        set_name(HIR"��"HIY"��"HIB"��"HIW"'"HIG"��"NOR, ({"mms"}));
	set_weight(20);
	if (clonep())
	    set_default_object(__FILE__);
	else {
	set("unit", "��");
	set("long", "һ��������ɫ��"+this_object()->name()+"�ɿ���������������𡫡� ֻ���ڿڲ������֡�\n");
	set("eat_msg", "$N����һ��"+this_object()->name()+"�ɿ������Ž����������Ц��˵�����һ�Ҫ���� \n");
	set("value", 1000000);
	set("drug_type", "��Ʒ");
	}
//  	set("is_monitored",1);

	setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(5);
  me->add_maximum_mana(5);
  message_vision(HIM "$N����һ��"+this_object()->name()+HIM"�ɿ������Ž����������Ц��˵�����һ�Ҫ����  \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
/*
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "ͻȻ���ڵ��ϣ������ˡ�\n");
    destruct(me);
}
*/
