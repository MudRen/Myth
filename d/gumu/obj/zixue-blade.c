//��Ѫ��
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;
inherit F_UNIQUE;

inherit BLADE;
#include <ansi.h>
void create()
{
        set_name(MAG"��Ѫ��"NOR, ({"zixue kuangdao", "dao","blade"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ��ͨ����ɫ�ı�����\n");
                set("unit", "��");
                 set("unique", 1);
                set("value", 12000);
                set("wield_msg", "$N��������һ����������������һ��������\n");
                set("unwield_msg", "$N���еı�������һ��������ʧ�ˡ�\n");
                set("weapon_prop/courage", 20);
                }
        init_blade(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "��ԯ��Ĺ"
                && me->query_skill("zizhi-blade",1) > 1)
    damage_bonus = me->query_skill("zizhi-blade",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/4; //

    victim->receive_wound("kee",damage_bonus,me);
    return MAG"��Ѫ"+NOR+HIW"��"+NOR+MAG"������һ��������\n" NOR;

}

