//�׹��
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit MACE;
#include <ansi.h>
void create()
{
        set_name(HIC"�׹��"NOR, ({"leiguang mace","mace","bian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�����͵���������·��ܴ������������������\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N�ӱ�����һ��ﵣ���ʱ���������������Ϊ֮ɫ�䡣\n"NOR);
                set("unwield_msg",HIW "$N΢΢һЦ,���е����ֽ���ಡ���һ�����ֶ���,�������...\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_mace(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "������"
                && me->query_skill("jinglei-mace",1) > 1)
    damage_bonus = me->query_skill("jinglei-mace",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIB"�׹��������������\n" NOR;

}

