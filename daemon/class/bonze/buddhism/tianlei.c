//wuyou@sk_sjsh
//2003-3-13
//���ǵ��������˺��жϱȽ��鷳
//�˺���ֵ�䶯̫��
//�����˷����������жϵ�һ�����
//���˺�ȴʹ����pfm�е��жϷ���
//���ǵ�������������cast��ʵ�ü�ֵҲ�Ͳ���̫����


#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;

        string tar_spells,tar_dodge;

        int ap,dp,dg,damage,chance,skills1,skills2;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ��˭���������ף�\n");
  
//        if( target->is_player() )
//                return notify_fail("��������Ŀǰ����������ʹ�á�\n");

        if (!target->is_fighting(me))
               return notify_fail("ֻ����ս���в���ʹ���������ף�\n");

        if((int)me->query("kee") < 200 )
                return notify_fail("���������㣬�ò����������ף�\n");

        if((int)me->query("force") < 200 )
                return notify_fail("����������������ʹ���������ף�\n");

        if((int)me->query_skill("buddhism", 1) < 430 )
                return notify_fail("��Ĵ�˷𷨻��������졣\n");

        if((int)me->query_skill("spells", 1) < 430 )
                return notify_fail("��Ļ����������������졣\n");

        if((int)me->query("mana") < 500 )
                return notify_fail("��ķ����������ٻ������������У�\n");

        msg = HIC"\n$N˫Ŀŭ��$n��������������������ܣ������콫���ҷ�ħ����
$NͻȻ����һ�ӣ�ɲ�Ǽ䣬������ӿ��Ũ���ܲ��������ƶ�վ�������콫��\n\n" NOR;

/*****************************************************************************/
/*��һ��*/
        msg +=HIY "   ������\n";
        msg +=HIY "   ����\n";
        msg +=HIY "   ������\n\n"; 
        msg +=HIY "�����ŵ���������һ����⻯��һ����������$n��\n"NOR;
 
        ap=(int)me->query_skill("buddhism", 1)
              +(int)me->query_skill("spells", 1)/2;

        tar_spells=target->query_skill_mapped("spells");
        if (! tar_spells) dp=(int)target->query_skill("spells", 1)/2;
        else dp=(int)target->query_skill("spells", 1)/2
              +(int)target->query_skill(tar_spells, 1);

        tar_dodge=target->query_skill_mapped("dodge");
        if (! tar_dodge) dg=(int)target->query_skill("dodge", 1)/2;
        else dg=(int)target->query_skill("dodge", 1)/2
              +(int)target->query_skill(tar_dodge, 1);
        if (dp!=0) dp=100*ap/dp/3+random(100*ap/dp)/2; else dp=100;
        if (dg!=0) dg=100*ap/dg/3+random(100*ap/dg)/2; else dg=100;

        damage=me->query("max_mana")/20+1;
        damage=(me->query("mana_factor")+me->query("str")+random(damage))*2;
        if (dp<30)
          {           
          msg += HIC "$n��æ���˽�$N�Ľ��ƿ���\n"NOR;
          message_vision(msg, me, target);
          }
        else if (dg<50)
          {           
          msg += HIC "$n�������һԾ����������һ����\n"NOR;
          message_vision(msg, me, target);
          }
        else 
          {           
          msg += HIC "$n�ۿ��Ž����������û���ƿ����������񽫵Ľ��������ס��$N��æ�ٳ�һ����⣬"
              +"$n�����˸����ţ�\n"NOR;
          message_vision(msg, me, target);
          target->receive_damage("kee",damage,me,"cast");
          target->receive_wound("kee",damage,me,"cast");
          if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
          COMBAT_D->report_status(target); 
          }
/***************************************************************************************/
/*�ڶ���*/      
        msg = HIG "   ������\n";
        msg +=HIG "   ��ľ��\n";
        msg +=HIG "   ������\n\n"; 
        msg +=HIG "�����������ľ���񽫻������̹����$n��\n"NOR;
        
         damage = (int)(random(me->query_skill("spells")/20)) + (int)(me->query_skill("spells")/20)+ 1;
        ap = me->query_skill("spells");
        ap =  ap * ap * ap / 100;
        dp = target->query("combat_exp")* 4 /5;
        if( dp<1 ) dp = 1;
        chance = (int)(random(ap + dp) * 100 / dp);
        if( chance > 66 ) 
        {
            damage = damage * 20 ;
            msg += HIC "���$n������̹�͸�������\n" NOR;
            target->receive_wound("kee", damage, me);
            target->receive_damage("kee",damage,me);
            if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
           
         }
         else if ( chance > 33 ) 
        {
            damage = damage * 10 ;
            msg += HIC "$n����������������̹���������\n" NOR;
            target->receive_wound("kee", damage,me,"cast");
            target->receive_damage("kee",damage,me,"cast");
            if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));   
         } 
         else{
         msg += "���Ǳ�$nȫ�㿪�ˡ�\n";
         }
         message_vision(msg, me, target);
         if( damage > 0 ) COMBAT_D->report_status(target);
         else if( damage < 0 ) COMBAT_D->report_status(me);
/*******************************************************************************/
/*������*/
        msg = HIW "   ������\n";
        msg +=HIW "   ��ˮ��\n";
        msg +=HIW "   ������\n\n"; 
        msg +=HIW "ˮ���񽫷���Ϊ�ƣ�����Ϊ�꣬�����������ű���Ѹ�Ͷ�����\n"NOR;

        ap=(int)me->query("daoxing",1);
        dp=(int)target->query("daoxing",1);
        skills1=(int)me->query_skill("spells",1);
        skills1=skills1*skills1*skills1/10;
        skills2=(target)->query_skill("spells",1);
        skills2=skills2*skills2*skills2/10;
        damage = (int)(me->query_skill("buddhism"))+ 1;
        if( random(ap+skills1) > (dp+skills2)/4 ) 
        {       
                msg += HIC"$n�������������������\n"NOR;
                target->receive_damage("kee", damage,me,"cast");
                target->receive_wound("kee", damage,me,"cast");
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                message_vision(msg, me, target);
                COMBAT_D->report_status(target,0);
         }
         else{
         msg += HIC"$n��Χ�γ�һ�������ܣ�û���ܵ�˿���˺���"NOR;
         message_vision(msg, me, target);
        }

/**************************************************************************************/
/*���Ļ�*/  

        msg = HIR "   ������\n";
        msg +=HIR "   ����\n";
        msg +=HIR "   ������\n\n"; 
        msg +=HIR "������˫�Ʋ�����һ�޴�Ļ�������$n��\n"NOR;
        ap = me->query_skill("buddhism");
        ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (me->query_skill("spells")+ me->query_skill("buddhism"))/2 ;
                msg +=  HIC "������$n������ը���ˣ�\n" NOR;
           
                target->receive_damage("kee", damage,me,"cast");
                target->receive_wound("kee", damage,me,"cast");
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                message_vision(msg, me, target);
                if( damage > 0 ) COMBAT_D->report_status(target);

        } else
                {
                msg += HIC"���Ǳ�$n����Ķ㿪�ˣ���\n";
                message_vision(msg, me, target);
                }      

/*****************************************************************************************/
/*�����*/

        msg = MAG "   ������\n";
        msg +=MAG "   ������\n";
        msg +=MAG "   ������\n\n"; 
        msg +=MAG "�����񽫽�����֮��ᵽ���У�����$n��\n"NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp /4) {
                
                damage = (me->query_skill("spells")+ me->query_skill("buddhism"))/2 + random((me->query_skill("spells")+ me->query_skill("buddhism"))/2) ;

                if( damage > 0 ) {

                        msg += HIC "���$n���Ҹ����ţ���ʱѪ���ɽ������˲��ᣡ\n" NOR;
                        target->receive_damage("sen", damage,me,"cast");
                        target->receive_wound("sen", damage,me,"cast");
                        target->receive_damage("kee", damage,me,"cast");
                        target->receive_wound("kee", damage,me,"cast");
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                }

             } 
        else
             {
                         msg += HIC"����$n���Ѵ���֮���ֽ����������ԭ����\n";
              }

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);


         me->add("force", -500);
         me->add("mana", -500);

         if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
                        me->kill_ob(target);
                }
                me->kill_ob(target);
        }

         me->start_busy(2);

         return 1;
}

