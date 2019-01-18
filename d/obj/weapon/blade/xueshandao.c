// blade.c

#include <weapon.h>

inherit BLADE;

string *names = ({
  "���µ�",
  "������",
  "��ͷ��",
  "�Ͻ�",
});

string *ids = ({
  "liu yue dao",
  "feng ming dao",
  "gui tou dao",
  "zi jin dao",
});


void create()
{
        int ii;
        ii=random(sizeof(names));
        set_name(names[ii], ({ids[ii], "blade", "dao"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1500);
		set("material", "steel");
		set("long", "һ������������"+this_object()->query("name")+"��\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(35);
	setup();
}
