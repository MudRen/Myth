// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIB"����"NOR, ({"yao dao", "dao","blade"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
              set("no_put",1);
              set("no_sell",1);

		set("material", "iron");
		set("long", HIY"�Ϲ�ʮ�����֮һ�������\n"NOR);
		set("wield_msg", "$N���һ�����������$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
        init_blade(90+random(25));
	setup();
}
