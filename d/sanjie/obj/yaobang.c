// yaobang.c ��������

#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(RED"��������"NOR, ({"langya yaobang","yaobang", "bang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ�����������Ǵ��������õı���\n");
                set("unit", "��");
		set("wield_msg","$n"RED"�������س��$N�������У������ִ������Ļ�Ӱ��\n"NOR);
		set("unwield_msg",RED"$N������$n"NOR+RED"һ�գ����ڱ���\n"NOR);
                set("value", 5000);
		set("weapon_prop/courage", 100);
		set("replace_file", "/d/sanjie/obj/bintiegun");
        }
        init_stick(100);
        setup();
}
