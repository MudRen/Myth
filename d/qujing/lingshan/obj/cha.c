//Cracked by Roath

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ɲ�", ({"xian cha", "cha", "tea"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ����������\n");
    set("unit", "��");
    set("value", 2000);
    set("max_liquid", 20);
    set("material", "jade");
  }
  
  set("liquid", ([
    "type": "water",
    "name": "��ɽ��Ȫ��",
    "remaining": 20,
   ]) );
  set("no_get", "�ɲ�����ɽ֮����������ߣ�\n");
  setup();

}

