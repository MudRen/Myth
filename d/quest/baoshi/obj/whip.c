// whip.c

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIM"��˿"NOR, ({"qing si","whip"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"�Ϲ�ʮ�����֮һ����˿\n"NOR);
                set("unit", "��");
                set("no_put",1);
                set("value", 0);
                set("no_give",1);

        }
        init_whip(100+random(100));
        setup();
}

