// blade.c
#include <ansi.h>
#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;

void create()
{
set_name(HIW "���߱�" NOR, ({"snake whip", "whip"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","�����������ң������Ѩ����������Ƥ���ɵı��ӡ�\n");
                set("unit", "��");
	set("replace_file", "/d/obj/weapon/whip/pibian");
set("value", 15000);
 set("wield_msg", "$N����һ˦��һ������Ƥ����������\n");
		set("unwield_msg", "$N������$n�������䣮\n");
		set("weapon_prop/courage", 5);
        }
        init_whip(200);
        set("is_monitored",1);
        setup();
}
mixed hit_ob(object me, object victim)
{
victim->apply_condition("snake_poison",(int)victim->query_condition("snake_poison")+random(3));
message_vision("$N����һ������ɫ������࣡\n", victim);
}
