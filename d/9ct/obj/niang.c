// ��ϼ���� by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_put","��ϼ���𻯳�һ˿����,������ʧ�ˡ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIR "��ϼ����" NOR , ({"xixia xianniang", "xian niang","xianniang","niang"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "������ϼ�����е���ϡҩ�ơ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xixia xianniang" && arg!="niang")   return 0;
  
  me->add("eff_sen",(random(2)+9));
  message_vision(HIG "$N����ؽ�һ����ϼ����ȸ����⣬һʱ��ȫ��һ����ɫ�����֡�\n" NOR, me);
  destruct(this_object());
  return 1;
}

