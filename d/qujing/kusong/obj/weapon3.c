//Cracked by Roath
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("������", ({"iron whip", "lian", "whip"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ������������������մ����Ѫ��\n");
                set("unit", "��");
                set("value", 500);
        }
        init_whip(30);
        setup();
}

