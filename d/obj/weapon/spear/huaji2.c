// blade.c

#include <weapon.h>
#include <ansi.h>
//  inherit F_UNIQUE;

inherit SPEAR;

void create()
{
set_name(HIW "���컯�" NOR, ({"huaji", "ji","spear"}));
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

 set("long","һ����һ�ɰˣ���ӧ���н�˵ķ��컯ꪡ�\n");
set("unit", "��");
set("replace_file", "/d/obj/weapon/spear/huaji");
set("value", 20000);
set("wield_msg", "$Nһ����������һ����ӧ���н�˵ķ��컯�\n");
set("unwield_msg", "$N������$n�����˱���\n");
set("weapon_prop/strength", 10);
        }
init_spear(100);
        setup();
}

