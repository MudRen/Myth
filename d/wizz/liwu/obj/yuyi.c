// yuyi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIW"����"NOR, ({ "yu yi", "yi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ������ë�Ƴɵ��·�����Ȼ�ܱ���ȴ��Ϊů�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 1000000);
		set("wear_msg", HIW "ֻ����ˢ����һ����$Nչ��һ����ɫ���������ϡ�\n" NOR);
		set("remove_msg", HIW "$N�����´����������������۵���СС��һ�š�\n" NOR);
		set("armor_prop/armor", 1000);
	}
	setup();
}
