// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("��ȸ��", ({"kongque ling","ling"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "��֧��ȸ���ϵ���ë��\n");
                set("unit", "��");
                set("base_unit", "֧");
                set("base_weight", 5);
                set("value", 3);
        }
        set_amount(random(5)+1);
        init_throwing(50);
        setup();
}

