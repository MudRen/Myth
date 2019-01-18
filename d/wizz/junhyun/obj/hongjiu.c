//ºì¾Æ
//junhyun@SK
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("²¨ç¾ÄÈ82", ({"portinas", "hongjiu", "jiu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Æ¿ÉÏºÃµÄ82Äê·Ý²¨ç¾ÄÈºì¾Æ¡£\n");
                set("unit", "Æ¿");
                set("value", 50);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "²¨ç¾ÄÈºì¾Æ",
                "remaining": 15,
                "drunk_apply": 5,
        ]));
}

