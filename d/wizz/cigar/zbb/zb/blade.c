// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_weight(4000);
        set_name(HIW"����"+HIR"�ֻ�"+HIB"��"NOR, ({"lunhui dao", "dao","blade"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
             set("value", 0);

                set("material", "steel");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
                set("wield_msg", "$N���һ����ض�ҡ��$n�������С�\n");
              set("no_put",1);
                set("long", WHT"�Ϲ�ʮ�����֮һ���ֻذ��Ե��\n"NOR);
	}
        init_blade(110);
	setup();
}
