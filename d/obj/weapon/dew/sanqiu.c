    //ˮ������
    //by dewbaby@sk


#include <ansi.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;

void create()
{
       set_name(HIC"ˮ������"NOR, ({"sanqiu fork","sanqiu","fork"}));
       set_weight(20000);
if( clonep() )
             set_default_object(__FILE__);
       else {
       set("long",HIC"��˵���Ƕ���������������������������Ĺ����ƺ���������İ��ء�\n");
             set("unit","��");
             set("value", 12000);
             set("wield_msg",HIC"$N��������һԾ����ס�˴��������$n"HIC"�����ˮ����������Ѹ��!\n"NOR);
             set("unwield_msg",HIC"$N����һ�ӣ����е�$n"HIC"ͻȻ��Ϊ���¶ˮ��ʧ��!\n"NOR);
             set("no_sell","�����������ɣ��ⶫ���㶼������\n");
             set("no_drog","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");

             set("weapon_prop/courage",20);
       }
       init_fork(130);
       setup();
}
/*
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    if( (string)me->query("family/family_name") == "��������"
             && me->query_skill("fengbo-cha",1) > 1)
    damage_bonus = me->query_skill("fengbo-cha",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIB"ˮ�����﷢������̲�֮��!\n"NOR;
}

*/
