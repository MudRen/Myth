// �����庮�� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
        set_name(HIC"�����庮��"NOR, ({ "yixian cha", "yixianluohan","fork","cha" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             set("value", 15000);
                set("material", "iron");
                set("long", "����һ����������������������\n");
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
        }
   init_fork(110);
        setup();
}

