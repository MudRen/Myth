//Cracked by Roath
// ajax  06/13/99

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;


string *names = ({
  "����",
  HIY"��ɫ����"NOR,
  "����",
});

void create()
{
   set_name(names[random(sizeof(names))], ({"fish"}));
   set_weight(100);
   if( clonep() )
           set_default_object(__FILE__);
   else 
     {
     set("long","һ�����㡣\n");
     set("unit", "��");
     set("value", 80000);
     set("no_sell","�ƹ��ҡ��ҡͷ�������ջ�������ģ�û�����棬��Ҫ��\n");
     set("food_remaining", 4);
     set("food_supply", 50);
     }
   setup();
}


