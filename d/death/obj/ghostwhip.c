//��˿
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIB"���ױ�"NOR, ({"ghost whip","whip","bian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","��������ڵ������һ��У���ɫ�Ĺ����ȻƮ���š�\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N���ҹ�����󣬽����ı��һ�����ޡ�\n"NOR);
                set("unwield_msg",HIB "$N���еĳ�����Ȼ���Ϊ���,Χ����$N.\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_whip(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "���޵ظ�"
                && me->query_skill("hellfire-whip",1) > 1)
    damage_bonus = me->query_skill("hellfire-whip",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIB"���ױ��Ϲ������\n" NOR;

}

