inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ɾ���", ({"jiu zhong", "jiuzhong", "zhong"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ��ʢ�ȾƵĴɾ��ѡ�\n");
     set("unit", "��");
     set("value", 70);
     set("max_liquid", 5);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "�Ⱦ�",
        "remaining": 7,
        "drunk_apply": 8,
      ]));
}

