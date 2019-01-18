//fake-jingubang.c
//the real jingubang may be used to improve stick level.
//this one is weapon only, less powerful,
//and simply put with ao-guang for highhands...weiqi:)

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit STICK;

void create()
{
	set_name( HIY "�𹿰�" NOR, ({ "jingu bang", "jingubang", "bang" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("Can_avoid_find", 1);
		set("no_sell", 1);
		set("no_give", 1);
//		set("no_get", 1);
		set("value", 5000);
		set("material", "gold");
        set("replace_file", "/d/obj/weapon/stick/bintiegun");
		set("long", "�˰���ͷ�Խ�Ϊ�����м���һ������������һ��С�֣�������𹿰�������������ơ���\n");
		set("wield_msg", "$Nһ���֣����ȼ������󣡴󣡴����к�Ȼ����һ��$n��\n");
		set("unwield_msg", "$Nһ������������ȣ�С��С��С��$n��$N����ת�˼�ת����Ȼ�����ˡ�\n");
	}
	init_stick(100);
	setup();
}
