//Cracked by Roath
// by snowcat dec 19 1997

inherit ITEM;

void create()
{
  set_name("ţͷ", ({"niu tou", "tou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ�ϵ���ţͷ��\n");
    set("unit", "ֻ");
    set("material", "bone");
  }
  setup();
}

