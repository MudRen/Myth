// created by snowcat on 12/18/1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "��ի��",
  "��ի��",
  "��ի��",
  "��ի��",
  "��ի��",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"zhai guo", "guo"}));
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һֻ����͸�ϵ�ի����\n");
    set("unit", "ֻ");
    set("value", 60);
    set("food_remaining", 3);
    set("food_supply", 120);
  }
//  set("no_sell",1);
}


