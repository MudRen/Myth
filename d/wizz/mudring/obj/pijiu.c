// wineskin.c  ¾Æ´ü

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("Çàµº"+YEL+"Æ¡¾Æ"NOR, ({"pijiu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¹ÞÇàµºÆ¡¾Æ¡£\n");
                set("unit", "¹Þ");
                set("value", 20);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "Æ¡¾Æ",
                "remaining": 15,
                "drunk_supply": 6,
        ]));
}


