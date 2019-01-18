// ǧ���� by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_put","ǧ���ݻ���һ����ˮ,������ʧ�ˡ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIG "ǧ����" NOR , ({"qianjue cao", "qianjuecao","cao"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���Ǿ���̨���е���ϡҩ�ġ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="qianjue cao" && arg!="cao")   return 0;
  
  me->add("max_force",(random(10)+90));
  me->add("max_mana",(random(10)+90));
  me->add("max_kee",(random(1)+9));
  me->add("max_sen",(random(1)+9));
  me->add("daoxing",(random(1000)+9000));
  me->add("combat_exp",(random(25000)+25000));
  me->set("food", (int)me->max_food_capacity()*10+random(100));
  me->set("water", (int)me->max_water_capacity()*10+random(100));
  message_vision(HIG "$N����ؽ�һ��ľ�����������У�һʱ��ȫ��һ������ɫ�����֡�\n" NOR, me);
  destruct(this_object());
  return 1;
}

