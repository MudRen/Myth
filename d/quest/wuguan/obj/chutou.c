//Cracked by Roath
// choutou.c ��ͷ

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("��ͷ", ({ "chu tou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صĳ�ͷ��������ò���������֪����ʱ�����������ݣ����ǳ��ˡ�\n");
		set("value", 0);
		set("rigidity",50);
            set("material", "steel");
		set("wield_msg", "$N����һ��$n���ڼ��ϡ�\n");
		set("unwield_msg", "$N��$n�Ӽ��Ϸ��������������ס�Լ��Ľš�\n");
	}
  	init_staff(15);
	setup();
}
