// ǧɫ��ϼ by Calvin

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIR"ǧɫ"+HIM"��ϼ"NOR, ({"qianse whip", "qiansezhaoxia","whip","zhaoxia"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","����һ���ɺ�ϼ������������ϼȾɫ֯�͵Ĳʴ���\n");
                set("unit", "��");
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("no_give", 1);
                set("wield_msg", "$N�������һ����ɫ�������˦�˳���\n");
		set("unwield_msg", "$N������$n�������䣮\n");
		set("weapon_prop/courage", 5);
        }
  init_whip(200);
        setup();
}

