//Cracked by Roath
// chaidao.c   ��
//by yfengf

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��", ({ "chai dao", "dao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "iron");
		set("long", "����һ���񵶣������ϻ��м�����ڣ�����ʮ�־��ˡ�\n");
		set("wield_msg", "$N���һ�Ѳ񵶵�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�����䡣\n");
	}
	init_blade(10);
	setup();
}
