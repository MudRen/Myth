 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�Ͷ���", ({ "you doufu", "doufu" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ��ը�ý�Ƶ������㶹����\n");
    set("unit", "��");
    set("value", 140);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

