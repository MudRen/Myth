
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��ζ������", ({"doufu geng", "geng"}));
  set_weight(400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��ɰ����ζ��������ð��������\n");
    set("unit", "��ɰ��");
    set("value", 310);
    set("food_remaining", 14);
    set("food_supply", 20);
  }
}

