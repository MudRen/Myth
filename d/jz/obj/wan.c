//Cracked by Roath

inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("[36m����[m", ({"haiwan", "wan"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "һ�������Ĵ��롣\n");
     set("unit", "��");
     set("value", 100);
     set("max_liquid", 30);
   }
   set("liquid", ([
     "type": "water",
     "name": "���",
     "remaining": 10,
     "drunk_supply": 10,
   ]));
}
