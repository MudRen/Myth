// created by snowcat
// 5/22/1997

#include <weapon.h>
#include <armor.h>
#include "hair.h"

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("��ɫ��ë", ({ "white hair", "whitehair", "hair" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ѵ���ɫ�ĺ�ë����������������ϣ�transform����\n");
    set("unit", "��");
    set("value",10000);
  }
  set("no_drop",1);
  set("no_get",1);
  set("no_sell",1);
  setup();
}

string name_suffix()
{
  string *strs = ({
    "ˮ",
    "��",
    "��",
    "֭",
    "¶",
  });
  return strs[random(sizeof(strs))];
}

string new_unit()
{
  return "��";
}

int init ()  
{   
  add_action ("do_transform", "transform");
  add_action ("do_drink", "drink");
  return 1;
}

int do_drink (string arg)
{
  object me = this_player();
  object ob = this_object();

  if (!arg || present (arg,environment(ob))!=ob)
    return 0; // to invoke standard function
  if (!ob->query("has_transformed")) {
    tell_object (me,"���Ƚ������������Ҫ�����ϡ�\n");
    return 1;
  }
  me->set("water", (int)me->max_water_capacity());
  message_vision ("$N����$nһ����������ȥ����������Ķ��ӡ�\n",me,ob);
  destruct(ob);
  return 1;
}

