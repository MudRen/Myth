#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【九华遗书】", ({ "jiuhua yishu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "武籍。九华先生遗著。此书载有内家武功练气之方、七迟掌、点穴解穴之法、吼龙掌、化身大法、金刚十八剑、离心大禁制、金刚般若神功等奇妙武功。\n");
          }

    setup();
}
