#include <weapon.h>

inherit BOW; 

void create()
{
        set_name("ľ��", ({"mu gong", "bow", "gong"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ��ľ�ƵĶ̹���\n");
                set("unit", "��");
		set("value", 100);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "wood");
        }

        init_bow(1);
        setup();
}

