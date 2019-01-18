// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name(YEL"�ݹǵ�"NOR, ({"kugu dao", "kugudao", "kugu", "dao", "blade", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
                set("is_monitored", 1);
		set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("material", "bone");
		set("name_recognized", "�ݹǵ�");
		set("long", "����һ������ɫ�ĵ������������ᡣ\n");
		set("wield_msg", "$N������ͻȻ�ӹ�һĨ����ɫ���ٿ�ʱ�����ж���һ��$n��\n");
		set("unequip_msg", "$N���ֽ�$n������У���ɫҲ��֮һ����\n");
	}
        init_blade(120);
	setup();
}
