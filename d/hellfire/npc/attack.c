#include <ansi.h>
#include <combat.h>
inherit F_DBASE;

void auto_attack(object me,object victim,object weapon,int attack_type)
{
         mapping my, your, action;
         string hell_type , msg;
         int same_pos,ap,dp,damage,damage_add;

         my = me->query_entire_dbase();
         your = victim->query_entire_dbase();

    if(!victim) return;
    if(! userp(victim) || ! living(victim) || !me->is_fighting(victim) || victim==me ) return ;
    if( environment(me)!=environment(victim) ) return;

    if(victim->query("kee") < 0 || victim->query("sen") < 0 ) return ;

    if (victim->query_temp("hell_died"))  return;

    if( me->query_temp("position/xx")== victim->query_temp("position/xx")
                 &&  me->query_temp("position/yy")== victim->query_temp("position/yy"))
                  same_pos=2;
                  else same_pos=1;

    if(!me->query("hell_type"))   hell_type="";
                  else hell_type=me->query("hell_type");

        ap = CITY_D->hell_skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
        if( ap < 1) ap = 1;

        dp = CITY_D->hell_skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;
        if( victim->is_busy() ) dp /= 2;



     if( random((ap * same_pos + dp )/10) > dp/5)
    {
        damage =(my["max_kee"]+my["max_sen"])/10+my["level"];
        damage +=(int)me->query_temp("apply/damage");
      damage /=4;
     if(me->query("levelup")) damage *= me->query("levelup");
        damage -=((int)victim->query_temp("apply/armor"));



    switch (hell_type)
                 {
                  case "����":
                  case "������":
                                me->set_temp("position/zz",0);
                                damage += 100 * same_pos ;
                                msg="���������һ�Ѷ̷ɽ���\n";
                                break;
                  case "ħ��ʦ":
                                 damage += 150 * same_pos ;
                                 msg="ʩ����һ��С����\n";
                                 break;
                  case "�ս���":
                                damage += 170 * same_pos ;
                                msg="ʩ����һ��С���硣\n";
                                break;
                   case "������":
                                damage += 250 * same_pos ;
                                msg="���һ����\n";
                                break;
                   case "���ڵ���ʹ��":
                                damage += 150 * same_pos ;
                                msg="�³�һ����̵��\n";
                                break;
                   case "Ұ����":
                                damage += 200 * same_pos ;
                                msg="����һ�����ȭ��\n";
                                me->set_temp("position/zz",0);
                                break;
                   default :
                                damage += 100 * same_pos ;
                                msg=sprintf( "%s%s��%s������ʩ����һ�Ѱ�����\n",hell_type,me->name(),victim->name());
                                break;
                   }


             if(damage>0)
                  {
                   victim->receive_damage("kee",damage,me);
                   victim->receive_damage("sen",damage,me);
                  if(me->query("levelup") && random(ap+dp)/3 >dp/2) 
                        {
                         victim->receive_wound("kee",damage,me);
                         victim->receive_wound("sen",damage,me);
                         }
                   message_vision( hell_type+"$N��$n"+msg+"$n�����ˣ�\n",me,victim);
                   COMBAT_D->report_status(victim, 0);

                  }
       }

}


