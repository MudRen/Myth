// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("�ο�ľ��", ({"zhuo zi", "zhuozi", "table"}));
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ���ο�ľ����\n");
    set("material", "wood");
    set("unit", "��");
    set("value", 1200);
  }
  setup();
}

