// created 6/8/97 pickle
// lingjian.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("����",({"zhu zi", "zhu", "zi", "zhuzi", "pillar"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����¥��һ�����ӣ������в��ٸ����ĺۼ���\n");
		set("unit","��");
		set("name_recognized", "����¥����");
		set("value", 0);
		set("material","wood");
		set("wield_msg","$N�ۼ��������ˣ�ʵ���ڲ����������ɴ���$n�������ˡ�\n");
		set("unwield_msg","$N���ˡ���һ����$n���£�����������һ������\n");
	}
	init_staff(30, TWO_HANDED);
	setup();
}
