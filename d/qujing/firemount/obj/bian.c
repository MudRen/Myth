// bajiaobian

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("�Ž���", ({"bajiao bian", "bian", "whip"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ�������İŽ��ޣ��������������죮\n");
                set("unit", "��");
                set("value", 500);
        }
        init_whip(5);
        setup();
}

