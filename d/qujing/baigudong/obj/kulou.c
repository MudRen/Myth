// copy from baigu  by smile 12/07/1998

inherit ITEM;

void create()
{
  set_name("����", ({"kulou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����á�\n");
    set("unit", "��");
    set("material", "bone");
  }
  setup();
}

