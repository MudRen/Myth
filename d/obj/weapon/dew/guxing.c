    //һ�����
    //by dewbaby@sk

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
       set_name(HIW"һ�����"NOR, ({"yiyi sword","yiyi","sword"}));
       set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
       else {
          set("unit","��");
          set("value","12000");
          set("material","silver");
          set("long",HIW"������Զ���ɵĻ�������������Ʈ�����ꡣ��ɢ���������׹⣬�������أ�\n"NOR);
          set("wield_msg",HIW"$NĬ���ľ���ֻ��$n"HIW"�������������$N����!\n"NOR);
          set("unwield_msg",HIW"$NĬ���ľ���$n"HIW"��ʱ��ʧ����Ӱ����!\n"NOR);
          set("no_sell","������������? �ⶫ����Ҳ����? \n");
          set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
  }
     init_sword(130);
     setup();
  }
/*
      mixed hit_ob(object me, object victim)   
{
               int damage_bonus = 0;   

             if( (string)me->query("family/family_name") == "��ׯ��"   
                             && me->query_skill("sanqing-jian",1) > 1)   
                     damage_bonus = me->query_skill("sanqing-jian",1);   
                     damage_bonus = (damage_bonus+random(damage_bonus))/2;   

                       victim->receive_wound("kee",damage_bonus);   
                     return HIR"һ����������ֳ�һ˿˿Ѫ��! \n" NOR;   
   }
*/
