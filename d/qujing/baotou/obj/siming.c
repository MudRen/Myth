
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("������", ({"siming chan", "chan", "staff"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 3500);
		set("material", "iron");
		set("long", "����һ�����������������ִֵ���ͷ��һ����\n");
		set("wield_msg", "$N����һ��������$n�����˵Ĳ�ͷ����������\n");
		set("unequip_msg", "$N�����������е�$n��\n");
	}
	init_staff(65);
	setup();
}
