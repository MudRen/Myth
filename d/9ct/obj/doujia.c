// ǧ�϶��� by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_put","ǧ�϶��Ի���һ����ˮ,������ʧ�ˡ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(MAG "ǧ�϶���" NOR , ({"qianzi doujia", "doujia","jia"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����ǧ�������е���ϡҩ�ġ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="qianzi doujia" && arg!="doujia")   return 0;
  
  me->add("bellicosity",(random(1)+49));
  me->add("balance",(random(10000)+500000));
  message_vision(HIG "$N����ؽ�һ��ǧ�϶����������У�һʱ��ȫ��һ���Ϲ����֡�\n" NOR, me);
  destruct(this_object());
  return 1;
}

