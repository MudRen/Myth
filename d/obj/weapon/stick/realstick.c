// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit STICK;

void create()
{
	set_name( HIY "�𹿰�" NOR, ({ "jin gu bang", "jingubang", "bang" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("value", 1000000000000);
      set("no_sell","С��С����Ӫ��������ô���صı��\n");
    set("no_give","�𹿰��ԶԷ�����̫���ˡ�\n");
		set("material", "gold");
		set("replace_file", "/d/obj/weapon/stick/bintiegun");
		set("long", "�˰���ͷ�Խ�Ϊ�����м���һ������������һ��С�֣�������𹿰�����\n");
		set("wield_msg", "$Nһ���֣����ȼ������󣡴󣡴����к�Ȼ����һ��$n��\n");
		set("unwield_msg", "$Nһ������������ȣ�С��С��С��$n��$N����ת�˼�ת����Ȼ�����ˡ�\n");
	}
	init_stick(250);
	setup();
}
