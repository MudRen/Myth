//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>

inherit STAFF;
#include <ansi.h>

void create()
{
        set_name(HIY"��ħ��"NOR, ({"xiangmo zhang", "zhang", "staff"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "steel");
                set("long", "���Ǿ��������Ƶı�����\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������\n");
        }
        init_staff(100);
        setup();
}

