    //��Ц��Ȫ
    //by dewbaby@sk


#include <weapon.h>
#include <ansi.h>
//  inherit F_UNIQUE;

inherit WHIP;
void create()
{
    set_name(HIR"��Ц��Ȫ"NOR,({"death whip","death","whip"}));
    set_weight(20000);
if( clonep() )
       set_default_object(__FILE__);
    else{
    set("long",HIR"һ������ϸ�Ĺ���֮�ޣ�����մ����Ѫ��ɢ����һ˿˿ɱ��!\n"NOR);
    set("unit","��");
    set("value", 12000);
    set("wield_msg",HIR"$N����һЦ�������м�����˿˿ɱ����\n"NOR);
    set("unwield_msg",HIR"$N�����Ȼ�����ַ�������$n"HIR"����Ȼ��ʧ!\n"NOR);
    set("no_sell","������������? �ⶫ����Ҳ����? \n");
    set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
    }
      init_whip(130);
      setup();

}
/*
    mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0; 

    if( (string)me->query("family/family_name") == "���޵ظ�" 
              && me->query_skill("hellfire-whip",1) > 1) 
    damage_bonus = me->query_skill("hellfire-whip",1); 
    damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("kee",damage_bonus); 
    return HIB"��Ц��Ȫ��ȼ��������!\n" NOR; 

}
*/
