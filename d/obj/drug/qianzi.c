// ǧ�϶���
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ�ɣ�ǧ�϶��Դ�ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIG "ǧ�϶���" NOR , ({"qianzi doujia", "doujia","dou","jia"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "ǧ�����Ͻ���Ķ���,����ġ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="doujia" && arg!="qianzi doujia")   return 0;
  
 
  me->add("potential", 20000);
  message_vision(HIG "$N��������һ��ǧ�϶����������У�һʱ���������ࡣ
ֻ��$N��Ϊ����,��Ƭ��֮��$N������������ˣ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

