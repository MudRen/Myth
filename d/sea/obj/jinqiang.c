// jinqiang.c

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIY "���ǹ" NOR, ({ "jin qiang","qiang","jinqiang" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "gold");
                set("long", "��ǹ�Իƽ�ΪͷͭΪ�ˡ�\n");
                set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
        //      set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
        init_spear(50);
        setup();
}

