// fake-tao.c ⨺��Ҹ�

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
  set_name(GRN"⨺��Ҹ�"NOR, ({"mihou taogan","mihoutaogan","tao","gan","taogan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�Ƴȳȵ�һ��⨺��Ҹɡ���˵���ɰ���������ɽ������⨺����Ƴɣ���ǿ�����������ٵĹ�Ч��\n");
set("value", 1000);
	set("drug_type", "�ٻ�");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  if((int)me->query("food")*100>(int)me->max_food_capacity()*90)
    return notify_fail("���Ѿ��Ե�̫��������ֺ��Ҹ���ȥ��Ҫ�����ˡ�\n");
  
  me->add("food", 50);
  if(random(10)==1){
      me->add_maximum_force(1);
    message_vision(HIG "$N����һ���ֺ��Ҹɣ��̲�סץ�����������˵�ֱ�뷭��ͷ�� \n" NOR, me);
    destruct(this_object());
    return 1;
  }
  if(random(10)==2){
      me->add_maximum_mana(1);
    message_vision(HIG "$N����һ���ֺ��Ҹɣ��̲�סץ�����������˵�ֱ�뷭��ͷ�� \n" NOR, me);
    destruct(this_object());
    return 1;
  }
  message_vision(HIG "$N����һ���ֺ��Ҹɣ��̲�ס�������촽�������޵����óԣ��óԣ�\n" NOR, me);
  destruct(this_object());
  return 1;
}
