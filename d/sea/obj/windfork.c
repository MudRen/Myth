//������
//by wuyou

#include <weapon.h>
//  inherit F_UNIQUE;

inherit FORK;
#include <ansi.h>
void create()
{
        set_name(HIB"������"NOR, ({"wind fork","fork","cha"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�̲�����,����ɪɪ,���˿�ȥ���������ޱߵĴ�,�ƺ������������Ŷ��������ܣ�\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N����һ������,һ������ɫ�ķɲ�������,�������У�\n"NOR);
                set("unwield_msg",HIW "$N����һ˦,���еķ����桰ಡ���һ�����ֶ���,�������...\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_fork(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "��������"
                && me->query_skill("fengbo-cha",1) > 1)
    damage_bonus = me->query_skill("fengbo-cha",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIW"�����淢������������\n" NOR;

}

