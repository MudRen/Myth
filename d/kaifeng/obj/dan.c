
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
set("no_get","������ģ���Ҳ��Ҫ��\n");
set("no_give","�Լ��ðɣ������Ǹ��ˣ�\n");
set("no_drop","����Ҫ�ˣ���Ҳ̫�˷��ˣ��������Űɣ�\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
set_name( GRN "�鵤" NOR , ({"ling dan", "dan"}));
  set_weight(90);
set("value", 20000); 
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
set("long", "���˲κ�ţ�����Ƶĵ�ҩ��\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan" && arg!="ling dan") return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
message_vision(HIG "$N����һ���鵤��������ƮƮ�ģ�һ���ָֻ���
ֻ��$Nɢ���߲����Σ�������������ˣ�\n" NOR, me);
destruct(this_object()); 
  return 1;
}

