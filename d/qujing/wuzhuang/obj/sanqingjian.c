//���彣
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIW"���彣"NOR, ({"sanqing sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�������壬�����˽������֮�����޿�ƥ�У�\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N�������˸���������������һָ��һ�����彣���������\n"NOR);
                set("unwield_msg",HIW "$Nһ�������ٷ�,��������ؽ���֮��.\n");
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
    
    if( (string)me->query("family/family_name") == "��ׯ��"
                && me->query_skill("sanqing-jian",1) > 1)
    damage_bonus = me->query_skill("sanqing-jian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIR"���彣������Ķ���\n" NOR;

}

