// gangcha.c

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("����", ({ "silver fork", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "iron");
                set("long", "һ��С�ɵ����档\n");
                set("wield_msg", "$N����һ��$n������������\n");
        }
        init_fork(40);
        setup();
}

