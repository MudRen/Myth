// shihun.c �ɻ��

#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(RED"�ɻ��"NOR, ({"shihun gun","stick", "bang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ�����������Ǵ���ħ�ı���\n");
                set("unit", "��");
		set("wield_msg","$n"RED"���$N�������У������ִ���ħ�Ļ�Ӱ��\n"NOR);
		set("unwield_msg",RED"$N������$n"NOR+RED"һ�գ����ڱ���\n"NOR);
                set("value", 5000);
                set("material", "gold");
		set("weapon_prop/courage", 100);
        }
        init_stick(80);
        setup();
}
