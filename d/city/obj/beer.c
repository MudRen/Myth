//Creat by waiwai@2000/12/20 

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
   set_name(HIY "һƿɢơ" NOR, ({"beer"}));
   set_weight(1000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "���ʵ��ൺ��ζɢơ��,ζ���ü���! \n");
     set("unit", "ƿ");
     set("value", 1);
     set("no_sell", 1);
     set("max_liquid", 400);
   }

   set("liquid", ([
     "type": "water",
     "name": "����ɢơ��",
     "remaining": 400,
     "drunk_apply": 20,
   ]));
}
