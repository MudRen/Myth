//Cracked by Roath

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIM"�ٻ���"NOR , ({"baihua niang", "wine"}));
  set_weight(500);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ƿ");
    set("long","�ٻ����Ӳɼ���ʱ�ɻ����Ƶ����ơ�\n");
    set("value", 800000);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
  set("remaining",random(100)+1);
}


void init()
{
  add_action("do_drink", "drink");
  add_action("do_add","add");
}

int do_drink(string arg)
{
  int food,water;
  object me = this_player();
  int max=(int)me->query("max_mana")*2;
  int flowers=query("flowers");

  if (arg!="baihua niang" && arg!="wine") return 0;
  
  if (me->query("water")>me->max_water_capacity())
    return notify_fail("����Ҳ�Ȳ����ˡ�\n");
  message_vision(HIG"$N����ٻ������һ�ڡ�\n"NOR,me);
  me->apply_condition("drunk", (int)me->query_condition("drunk")+1);
  add("remaining",-1);
  me->add("water",30);
  if (flowers) {
    if (flowers>5) flowers=5;
    message_vision(HIG"$N�е���̨�����ޱȣ�ɲ�Ǽ䷨�����ǡ�\n"NOR,me);
    me->add("mana",flowers*(80+random(40)));
    if (me->query("mana")>max) me->set("mana",max);
  }
  if (!query("remaining")) {
    message_vision("$N��һСƿ�ٻ���ȵľ��⣬���ְѾ�ƿ���ˡ�\n",me);
    destruct(this_object());
  }
  return 1;
}

int do_add(string arg) {
  object flower;  
  object me=this_player();
  if (!arg) return 0;
  if (!flower=present(arg,me)) return 0;
  if (flower->query("id")!="flower") return notify_fail("�㲻�����ٻ����ﶪ����������\n"); 

  if (flower->query("baihuaniang")) {
     message_vision(HIG"$N��һ��"+flower->query("name")+
       HIG"����ٻ����У�����������һ�������ҷҷ���˵������������\n"NOR,me);
     add("flowers",1);
  } else message_vision(HIR"$N��"+flower->query("name")+
       HIR"���飬�ӽ��ٻ����У������㣬Ư�ھ��У��������仨Ʈ��֮�С�\n"NOR,me);
  destruct(flower);
  return 1;
}
