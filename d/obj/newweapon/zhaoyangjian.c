//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIC "������" NOR, ({ "zhaoyang jian", "jian" }) );
    set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
                set("value", 10000);
//        	set("no_drop", "1");
        	set("material", "iron");
                set("long", "���ǳ�����ʦɱ�������������˲���ļ�����������\n");
        	set("wield_msg","�����࣬������ˣ�$n����$N�鵽���У����������졣\n");
        	set("unwield_msg", "$N��$n������䣬���������\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
               	}
        init_sword(105);
	setup();
}
