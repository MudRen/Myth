//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIC "��ˮ��" NOR, ({ "bishui jian", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_paimai", 1);
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "����������ˮɫ �����ޱȣ��ഫ����һλ��������ʦ֮�֡�\n");
                set("wield_msg","�����粨��������ˮ��$n������$N���У�\n");
                set("unwield_msg", "$N��$n������䣬���������\n");
                                set("no_sell",1);
                                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
                }
        init_sword(150);
        setup();
}

