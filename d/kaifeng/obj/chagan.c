inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���", ({"cha gan", "gan"}));
  set_weight(300);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һС�����ɣ�ɢ������ζ��\n");
    set("unit", "��");
    set("value", 85);
    set("food_remaining", 5);
    set("food_supply", 15);
  }
}

