//����ħ��
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit F_UNIQUE;
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIG"����ħ��"NOR, ({"qingyu mojian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ��ɢ������ɫ�����ı�����\n");
                set("unit", "��");
                set("value", 12000);
               set("unique", 1);
                set("wield_msg", "$N���־���һ����ɫ����������������һ��������\n");
                set("unwield_msg", "$N���е���������һ����ɫ������ʧ�ˡ�\n");
                set("weapon_prop/courage", 20);
                }
        init_sword(120); // so high...mudring
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "��ԯ��Ĺ"
                && me->query_skill("qinghu-jian",1) > 1)
    damage_bonus = me->query_skill("qinghu-jian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/4; //...

    victim->receive_wound("kee",damage_bonus);
    return HIG"����"+HIW"ħ��"+HIR"���������䣡\n" NOR;

}

