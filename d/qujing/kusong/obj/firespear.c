//������ǹ
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SPEAR;
#include <ansi.h>
void create()
{
        set_name(HIR"������ǹ"NOR, ({"honglian yaoqiang","spear","qiang"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ����ǹ��ǹ���������������档\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIR "$N��������һ˿���棬��̼����һ�˺�����ǹ\n"NOR);
                set("unwield_msg",HIR "$N������ǹ����һ��Բ��,˲����һ�Ż���,��ʧ������!\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_spear(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "���ƶ�"
                && me->query_skill("wuyue-spear",1) > 1)
    damage_bonus = me->query_skill("wuyue-spear",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIR"������ǹ������������档\n" NOR;

}

