// gangcha.c

#include <weapon.h>
#include <ansi.h>

inherit FORK;

void create()
{
        set_name(HIG"���"NOR, ({ "shen cha","cha","fork" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "iron");
                set("long", WHT"�Ϲ�ʮ�����֮һ����档\n"NOR);
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
        }
        init_fork(80+random(30));
        setup();
}

