// thin_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��ǽ�", ({ "linggu sword", "jian", "sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5000);
		set("material", "steel");
		set("long", "��ѽ���˵������Ѫ����Ʒ���������ɡ�\n");
		set("wield_msg", "һ��Ѫ��������$N�����Ѷ��˰�$n��\n");
	}
	init_sword(35);
	setup();
}
