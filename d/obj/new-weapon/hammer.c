#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
#include "/std/weapon/newwwd.c"; 


void create()
{
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���칬����֮���ķ𴸣��������Щ��׭�������֮�顣\n");
                set("value", 100000);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n����Х��أ���ס�����С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
     }
        init_hammer(105);
       updatename("hammer"); 
        setup();
}

