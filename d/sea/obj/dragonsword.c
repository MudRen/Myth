#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��Ȫ��", ({ "dragon sword", "jian", "sword" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
                set("long","һ�ѹ�ã����ı�����������Ӱ������\n");
                set("wield_msg", "$N���һ�ѽ���ϸ���Ľ����������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(50);
        setup();
}

