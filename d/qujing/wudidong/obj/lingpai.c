// lingpai.c
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("����",({"ling pai", "ling", "pai", "lingpai"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",RED"
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\t\t\t��
\n"NOR);
		set("unit","��");
		set("value", 0);
		set("name_recognized", "�׹���");
		set("material","bone");
		set("wield_msg","$N�ͳ�һ��$n�������������ݣ�Ȼ����������С�\n");
		set("unwield_msg","$NС������İ���$n�����������������$n������Ƶġ�\n");
	}
	init_dagger(5);
	setup();
}








