inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("ˮ�ƹ�", ({"jiu guan", "jiuguan", "guan"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ��װˮ�ƵĴ�ƹޡ�\n");
     set("unit", "��");
     set("value", 160);
     set("max_liquid", 25);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "ˮ��",
        "remaining": 25,
        "drunk_apply": 6,
      ]));
}

