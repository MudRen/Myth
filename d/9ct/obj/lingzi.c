// ѩ����֥ by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_put","ѩ����֥����һ����ˮ,������ʧ�ˡ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIW "ѩ����֥" NOR , ({"xueyu lingzhi", "lingzhi","xueyulingzhi"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���ǰ�Ұ�����е���ϡҩ�ġ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xueyu lingzhi" && arg!="lingzhi")   return 0;
  
  me->add("office_number",(random(2)+4));
  message_vision(HIG "$N����ؽ�һ��ѩ����֥�������У�һʱ��ȫ��һ���׹����֡�\n" NOR, me);
  destruct(this_object());
  return 1;
}

