//��ͤ��ҹ
//by dewbaby@sk

#include <weapon.h>

inherit WHIP;
#include <ansi.h>

void create()
{
       set_name(HIB"��ͤ��ҹ"NOR, ({"lanting whip","lanting","whip"}));
       set_weight(20000);
if( clonep() )
       set_default_object(__FILE__);
       else {
set("long",HIC"����Ǵ�˵�к�ϼ���ӳ۳�����ʱ���õı���֮һ����ϸ��ȥ������Լɢ���ŵ������������㡣\n"NOR);
              set("unit","��");
              set("value", 12000);
              set("wield_msg",HIB"$N����һЦ��ƮȻһ��ת���$n"HIB"�Ѿ���������$N�����ϡ�"MAG"һ�������㳯�����������\n"NOR);
             set("unwield_msg",MAG"һ��Ũ���������㽫�����֡�"HIB"ֻ��$N΢΢���ף�������ŵ��������Ѳ����������ϵ�$n��\n"NOR); 
              set("no_sell","�ⶫ����Ҳ����?���Խ���ë����! \n");
              set("no_drop","�ӵ���������ȥ��,���ӻ���Ⱦ����! \n");
             set("weapon_prop/courage", 20); 
      }
    init_whip(130);
    setup();
}
/*
 mixed hit_ob(object me, object victim) 
{
    int damage_bonus = 0; 

    if( (string)me->query("family/family_name") == "��˿��" 
                 && me->query_skill("yinsuo-jinling",1) > 1) 
    damage_bonus = me->query_skill("yinsuo-jinling",1); 
    damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("kee",damage_bonus); 
    return MAG"��ͤ��ҹ����Լ���ֳ�����֮��!\n" NOR; 
  }
*/
