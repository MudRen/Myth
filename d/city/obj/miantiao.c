//Last Create  By PKYOU@DHXY 2002/05/25

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "牛肉汤面",
  "辣鸡丝面",
  "红烧牛肉面",
  "牛肉拉面",
  "麻辣面汤",
});

void create()
{
  set_name("各式面条", ({"mian tiao", "miantiao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一碗热气腾腾的面条。\n");
    set("unit", "碗");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}

void init()
{
  if (query("name")=="各式面条")
    set_name(names[random(sizeof(names))], ({"mian tiao","miantiao"}));
//  ::init();
}
