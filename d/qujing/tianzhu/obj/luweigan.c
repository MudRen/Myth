
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("±ζ��", ({"luwei gan", "luweigan", "gan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����±ζ�ɡ�\n");
    set("unit", "��");
    set("value", 110);
    set("food_remaining", 6);
    set("food_supply", 25);
  }
}

