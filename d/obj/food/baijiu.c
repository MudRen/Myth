
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ִž�ƿ", ({"jiuping", "skin"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ������װ�ƵĴִž�ƿ����װ��������׾ơ�\n");
     set("unit", "��");
     set("value", 100);
     set("max_liquid", 15);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "�ϰ׸�",
        "remaining": 15,
        "drunk_apply": 15,
      ]));
}


