#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
        set_name( HIC "������" NOR, ({ "long fork", "fork" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���൱�������������������������㣬������Ҫ���ĺܡ�\n");
                set("value", 100000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
        }
        init_fork(105);
        setup();
}

