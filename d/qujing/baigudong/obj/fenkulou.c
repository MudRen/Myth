// created  by smile 12/07/1998

inherit ITEM;

void create()
{
  set_name("������", ({"fen kulou","kulou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�ѷ����á�\n");
    set("unit", "��");
    set("material", "bone");
  }
  setup();
}

