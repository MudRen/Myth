// copy from baigu  by smile 12/07/1998

inherit ITEM;

void create()
{
  set_name("�׹�", ({"bai gu","gu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ѱ׹ǡ�\n");
    set("unit", "��");
    set("material", "bone");
  }
  setup();
}

