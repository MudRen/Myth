//Cracked by Roath
// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����", ({ "biao" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"������һ��ʮ�ֳ����İ�����������ȴֻ��һ�����У�\n");
                set("unit", "Щ");
                set("base_unit", "֦");
                set("base_weight", 40);
                set("base_value", 50);
        }
        set_amount(30);
        init_throwing(20);
        setup();
}

