//Last Create  By PKYOU@DHXY 2002/05/25
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����������", ({"zhu rou", "zhurou", "fentiao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���������ڵ�������������\n");
    set("unit", "��");
    set("value", 1000);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
