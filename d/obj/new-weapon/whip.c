#include <ansi.h>
#include <weapon.h>

inherit WHIP;
#include "/std/weapon/newwwd.c"; 

void create()
{
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","һ����Լʮ�ߣ�����֮����޹�����ޡ�\n");
                set("unit", "��");
                set("value", 100000);
                set("wield_msg",
"ֻ����ž����һ����⣬$N����������һ����޹�����ޣ�\n");
                set("unwield_msg", "$N������$n�������䣮\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
        }
        init_whip(105);
       updatename("whip"); 
        setup();
}

