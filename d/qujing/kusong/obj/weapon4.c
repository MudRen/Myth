//Cracked by Roath
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("��ͷ��", ({ "iron fork", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "iron");
                set("long", "һ�������ĸֲ档\n");
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
        }
        init_fork(30);
        setup();
}

