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
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("material", "steel");
                set("no_give", 1);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
  init_stick(200);
        setup();
}

