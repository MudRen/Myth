// blade.c

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;

void create()
{
        set_name("��˿", ({"silk whip", "whip"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","һ����ɫ�ĳ�����ϸ��������ϸ��ë���ĳ�˿�۳ɣ����������ȴ�޿ײ��롣\n");
                set("unit", "��");
	set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 12000);
		set("wield_msg", "$N�������һ����ɫ�������˦�˳���\n");
		set("unwield_msg", "$N������$n�������䣮\n");
		set("weapon_prop/courage", 5);
        }
        init_whip(60);
        set("is_monitored",1);
        setup();
}

