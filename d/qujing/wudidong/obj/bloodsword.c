//Ѫ��
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(RED"Ѫ��"NOR, ({"blood sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","��ǧ����Ѫ��ն����ͷ­��һ��ħ����\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",RED "$N�������֣�һ�ε���Ѫ�����һ��Ѫɫ������\n"NOR);
                set("unwield_msg",RED "$N���е�Ѫɫ��������һ��Ѫ��,��$N����������!\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�"
                && me->query_skill("qixiu-jian",1) > 1)
    damage_bonus = me->query_skill("qixiu-jian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return RED"Ѫ���ϸ��ֳ����������Թ����\n" NOR;

}

