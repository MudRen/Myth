//�ȱ�����
//by wuyou

#include <weapon.h>
//  inherit F_UNIQUE;

inherit STAFF;
#include <ansi.h>
void create()
{
        set_name(HIY"�ȱ�����"NOR, ({"cibei fazhang","staff","zhang"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","�ȱ����ȷ���ҫ�۵ķ��,��������!\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$Nһ������ʨ�Ӻ�,���й�âͻ��,��Ȼ����һ�����ȣ�\n"NOR);
                set("unwield_msg",HIW "$N˫��һ��,�ȱ����ȡ�ಡ���һ�����ֶ���,�������...\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_staff(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "�Ϻ�����ɽ"
                && me->query_skill("lunhui-zhang",1) > 1)
    damage_bonus = me->query_skill("lunhui-zhang",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIY"�ȱ����ȷ�����գ�\n" NOR;

}

