#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name( HIC "ն���" NOR, ({"tian bang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
                set("long", "һ����ػ�Բ���������а�����������ͬһ�����������ڰ��ϡ�\n");
                set("value", 100000);
                set("material", "steel");
                set("wield_msg", "$N���䡹��һ�����һ��$n�������С�\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");

        }
        init_stick(105);
        setup();
}

