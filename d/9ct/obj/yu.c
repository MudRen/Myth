// ���� by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_put","���󻯳�һ����ˮ,������ʧ�ˡ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIG "����" NOR , ({"shu yu", "shu","yu"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���ǰ��������е���ϡҩ�ġ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="shu yu" && arg!="yu")   return 0;
  
  me->add("eff_kee",(random(2)+9));
  message_vision(HIG "$N����ؽ�һ�������������У�һʱ��ȫ��һ��������֡�\n" NOR, me);
  destruct(this_object());
  return 1;
}

