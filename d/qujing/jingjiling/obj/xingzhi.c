#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�ӻ�֦", ({ "xinghua zhi","zhi","jian", "sword" })
);
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "����һ��ϸ�����ӻ�֦�����滹�ж���ŵ��ӻ���\n");
                set("wield_msg", "$N������������ӻ���Ȼ��$n�������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(1);
        setup();
}

