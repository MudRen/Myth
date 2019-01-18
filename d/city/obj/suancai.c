//Last Create  By PKYOU@DHXY 2002/05/25

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("À·≤À", ({"suan cai", "cai", "suancai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "“ª≈ÃÀ·≤À°£\n");
    set("unit", "ÕÎ");
    set("value", 500);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
