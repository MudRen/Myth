// created 6/8/97 pickle
// lingjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("���",({"ling jian", "ling", "jian", "lingjian"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","һ֦�̶̵�С������дһ���������֡�\n");
		set("unit","֦");
		set("name_recognized", "�������");
		set("value", 0);
		set("material","bone");
		set("wield_msg","$N��æ���ڻ���һ�ͣ��ͳ�һ֦$n���������С�\n");
		set("unwield_msg","$NС������ذ�$n�Żػ���ĵ����ҿ�û�������ˡ�\n");
	}
	init_dagger(2);
	setup();
}
