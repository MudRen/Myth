//���쳯����
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR"���촿����"NOR, ({"chunyang jian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ��մ�������Ѫ�������ı�����ɢ����������η�ĺ�а֮�⣡\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N����һ�Σ������Ѷ���һ�����촿������\n"NOR);
                set("unwield_msg", "$N�������еĻ��쳯������\n");
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
    
    if( (string)me->query("family/family_name") == "����ɽ"
                && me->query_skill("huxiaojian",1) > 1)
    damage_bonus = me->query_skill("huxiaojian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIR"���촿����"+HIW"������˿˿��а֮�⣡\n" NOR;

}

