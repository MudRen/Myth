//Cracked by Roath
// created by ajax on 7/8/1999

#include <ansi.h>
#include <weapon.h>

//inherit F_UNIQUE;

inherit SWORD;

void create()
{
        set_name(HIM"��"+HIY"��"+HIG"��"NOR, ({ "zijin xiao","xiao","zijinxiao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
                set("long", BLU"�����ӵ��Ͻ����˵�����Ϻ����������һ���������ģ��ô����������������ף�����\n"NOR);
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("value", 30000);
//                set("replace_file", "/d/obj/weapon/sword/yudi");
		set("wield_msg", "$N����$n������������Ϊ����������Ϻ������ˡ�\n");
		set("unwield_msg", "$N����ή�ң��޾���ɵĽ�$n������䡣\n");
       	        set("weapon_prop/int", 2);
                set("music/type", "xiao");
	}
        init_sword(20);
	setup();
}
