#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;

inherit HAMMER;

void create()
{
        set_name(HIY "����" NOR, ({"falun", "lun","hammer"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","��˵����ͨ�ķ��������ڴ�����������������ôҲҪմЩ������\n");
                set("unit", "��");
	set("replace_file", "/d/obj/weapon/hammer/falun");
                set("value", 50000);
                set("wield_msg", "$N�ó�һ��$n���������л��˼��¡�\n");
                set("unwield_msg", "$N�������е�$n��\n");
		    set("material", "steel");
                            set("armor_prop/spells", 10);
}
init_hammer(150);
        set("is_monitored",1);
        setup();
}
