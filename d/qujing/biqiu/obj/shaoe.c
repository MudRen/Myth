// by snowcat 11/22/1997
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��ζ�ն�", ({ "wuwei shaoe", "shaoe", "e" }) );
  set_weight(180);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һֻ±���������ζ�ն졣\n");
    set("unit", "ֻ");
    set("value", 300);
    set("food_remaining", 4);
    set("food_supply", 45);
  }
}

