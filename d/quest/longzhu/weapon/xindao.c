// ��Ҷ�� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC"��Ҷ��"NOR, ({"xinye dao", "dao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɫ����Ҷ�ε�,�Ǵ�˵����Ҷͯ�ӵı��\n");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", MAG"$N��ھ�,��ৡ���һ���ɳ�һ��$n"NOR+MAG"��������,�������,��������\n"NOR);
                set("unwield_msg", MAG"$N��ھ�,��ǰ������$n"NOR+MAG"������Ϊһ�������ʧ�ˡ�\n"NOR);
        set("weapon_prop/courage", 120);
        }
        init_blade(50);
        setup();
}

