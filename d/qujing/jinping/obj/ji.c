 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��ը��", ({ "youzha ji", "ji" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һֻը�ý�Ƶ������㼦��\n");
    set("unit", "ֻ");
    set("value", 200);
    set("food_remaining", 4);
    set("food_supply", 40);
  }
}

