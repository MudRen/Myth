#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����ն", ({"dragon blade", "blade", "dao"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "iron");
                set("long", "����һ�ѷ��ź����䵶��\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(50);
        setup();
}

