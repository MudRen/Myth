//Cracked by Roath
// nine-ring.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit STAFF;

void create()
{
	set_name( HIY "�Ż�����" NOR, ({ "nine-ring staff", "staff" }) );
    set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_sell",1);
//                set("no_drop", 1);
//                set("no_give", 1);
//                set("no_put", 1);
			set("replace_file", "/d/obj/weapon/staff/budd_staff");
		set("long", HIY "����������������֮�Ż����ȣ����������Ÿ�ͭ�����������ޱߡ�\n" NOR);
		set("value", 50000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N�ó�һ���Ż������������У�ɲ�Ǽ�����һƬ���£�����ع���ҲΪ֮�𶯡�\n\n" NOR);
		set("unwield_msg", HIY "\n$N�������еľŻ����ȣ���Χ���˲Ŵ���һ��������\n\n" NOR);
	}

    init_staff(120);
	setup();
}
