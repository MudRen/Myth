// budd_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;
#include "/std/weapon/newwwd.c"; 

void create()
{
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ�����贳�ص�����֮�ȣ���������10���񻷣��������֮�顣\n");
                set("value", 100000);
		set("material", "brass");
		set("wield_msg", "$N�ó�һ������Ȼ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
	}

        init_staff(105);
       updatename("staff"); 
	setup();
}
