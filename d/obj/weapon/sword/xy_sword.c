// ��ԯ��.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��ԯ��", ({ "xuanyuan sword", "jian", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "steel");
                set("long", "����һ������Ψһ�ı���������͸��,�����ޱȡ�\n");
                set("wield_msg", "һ���Ϲ�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(80);
        setup();
}
