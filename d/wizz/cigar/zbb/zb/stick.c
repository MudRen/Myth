// ���� by Calvin

#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        set_name(HIY"����"NOR, ({"lingfo stick", "bang","stick"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
                set("long", "���䷲����͵�����,���ɫ������������⡣\n");
             set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
   init_stick(110);
        setup();
}

