//Cracked by fbbz
//Ansi 2001/10

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,damage,mypot;
        string msg;
        object weapon;
        int k1,k2,k3,k4;        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����꡹��\n");

        if(!me->is_fighting())
                return notify_fail("�����꡹ֻ����ս����ʹ�ã�\n");
                
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("������ɽ�Ĳ����á����꡹��\n");
                
        if ((int)me->query_skill("shushan-jianfa",1)<120)
                return notify_fail("�����ɽ������Ϊ��������ʹ����һ�л������ѣ�\n");
        if ((int)me->query_skill("yujianshu",1)<120)
                return notify_fail("�����������Ϊ��������ʹ����һ�л������ѣ�\n");
        if ((int)me->query_skill("mindsword",1)<120)
                return notify_fail("����Ľ���Ϊ��������ʹ����һ�л������ѣ�\n");
        if ((int)me->query_skill("canxin-jian",1)<120)
                return notify_fail("��Ĳ��Ľ���Ϊ��������ʹ����һ�л������ѣ�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 800 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        dp = target->query("combat_exp"); 
        ap = me->query("combat_exp"); 
     
        msg=HIW"\n$N���һ����"+HIR"����֮��Ψ����ɽ����"+HIB"�����꡹����������\n"NOR;
        msg += HIM"ֻ��$N���г����ڿ��л��˸��뻡��"+HIG"��������"+HIM"������������������$n��\n"NOR;
        k1=(int)me->query_skill("yujianshu",1);      
        mypot=k1*k1*k1/10 + ap;        
        if ( random( mypot+dp ) > dp*3/5 ) 
        {              
                damage = k1+random(k1)+me->query("force_factor");
                msg += HIC"���$n"+HIC"������"+HIG"��������"+HIC"���������\n"NOR;
                message_vision(msg, me, target);                                                                     
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm"); 
                COMBAT_D->report_status(target);                                 
        }
        else 
        {
                msg +="���Ǳ�$nȫ�㿪�ˡ�\n"NOR;
                message_vision(msg, me, target);       
        }
        msg = HIY"ֻ��$N������ת���������ģ�"+HIM"���Ľ���"+HIY"�������������ֱɨ��$n��\n"NOR;
        k2=(int)me->query_skill("mindsword",1);      
        mypot=k2*k2*k2/10 + ap;        
        if ( random( mypot+ dp) > dp*3/5 ) 
        {              
                damage = k2+random(k2)+me->query("force_factor");
                msg += HIC"���$n"+HIC"��ɨ�����ţ�\n"NOR;
                message_vision(msg, me, target);                                                                      
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg +="$n�����������ͼ�������˽��롣\n"NOR;
                message_vision(msg, me, target);       
        }
     
        msg = HIG"$N���г�����ͣ����������ؿڣ���ʱ����һ�Ʊ��߶�������˼��ԭ������"+HIB"�����Ľ���"+HIG"��\n"NOR;
        k3=(int)me->query_skill("canxin-jian",1);      
        mypot=k3*k3*k3/10 + ap;        
        if ( random( mypot+dp ) > dp*3/5 ) 
        { 
                damage = k3+random(k3)+me->query("force_factor");
                msg += HIC"���$n"+HIC"���޷������������Ľ���Ⱦ͸��\n"NOR;
                message_vision(msg, me, target);   
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg +="���Ǳ�$n�͵�һ�ɣ��㿪�ˡ�\n"NOR;
                message_vision(msg, me, target);       
                                 
        }
        msg = HIW"$N�����г���һ��������ԼԼ֮���ƺ�����һ���ӽ��зɳ�����Ȼ�����һʽ"+HIR"�����꡹"+HIW",�����ڽ�����֮�ƣ�\n"NOR;
        k4=(int)me->query_skill("shushan-jianfa",1);      
        mypot=k4*k4*k4/5 + ap;        
        if ( random( mypot+dp ) > dp/2 ) 
        {              
                damage = k4+k4+me->query("force_factor");
                msg += HIB"���$n"+HIB"���һ������"+HIR"����"+HIB"���У����Ǻ���Ҳ�ܵ����˺���\n"NOR;
                message_vision(msg, me, target);                                       
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen",damage/2,me,"pfm");
                COMBAT_D->report_status(target);                                
        }
        else 
        {
                msg +="$nһ����Ц��ԭ����ˣ�˵�ճ�����𣬲���˼��Ķ㿪�ˡ�\n"NOR;
                message_vision(msg, me, target);       
                                 
        }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("force",-300);
        me->start_busy(2);
        return 1;
}


