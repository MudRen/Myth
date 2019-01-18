// BY wuyou@sk_xyj 2002-12-1

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
    int ap, dp, damage, mypot;
    string msg;
    object weapon;
    int k1, k2, k3;        

    if (!target)
        target = offensive_target(me);

    if (!target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
            return notify_fail("��Ҫ��˭ʩչ"HIG"�����ˡ���"+NOR"������\n");
    
    if (!me->is_fighting())
        return notify_fail("�����ˡ���ֻ����ս����ʹ�ã�\n");
 
    if (!PFM_D->valid_family(me, "���޵ظ�"))
        return notify_fail("�����ˡ�����ڤ���ؼ���\n");
                
    if ((int)me->query_skill("zhuihun-sword", 1) < 200)
        return notify_fail("���׷�꽣�ȼ�������ʹ����һ�л������ѣ�\n");

    if ((int)me->query_skill("kusang-bang", 1) < 200)
        return notify_fail("��Ŀ�ɥ���ȼ�������ʹ����һ�л������ѣ�\n");

    if ((int)me->query_skill("hellfire-whip", 1) < 200)
        return notify_fail("����һ�޵ȼ�������ʹ����һ�л������ѣ�\n");

    if ((int)me->query_skill("gouhunshu", 1) < 200)
        return notify_fail("��Ĺ�������������ʹ����һ�л������ѣ�\n");

    if ((int)me->query("max_force") < 3000)
        return notify_fail("�������������\n");

    if ((int)me->query("force") < 800)
        return notify_fail("����������㣡\n");

    if ((int)me->query("sen") < 400)
        return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

    dp = target->query("combat_exp"); 
    ap = me->query("combat_exp"); 
     
    msg = HIW"\n$N˫�ֻ�һ��Բ����Ȼ������٣�������������������������" BLINK + HIG"�����ˡ���"
        NOR HIW "���С�\n" NOR;
    msg += HIW"     \n"NOR;
    msg += HIW"        "HBRED HIG"������������"NOR"       "HBRED+HIG"������������\n"NOR;       
    msg += HIW"        "HBRED HIG"��   "NOR BLINK HIR "߱" NOR HBRED HIG "   ��" NOR "       "
        HBRED HIG "��   " NOR BLINK HIR "��" NOR HBRED HIG "   ��\n"NOR;       
    msg += HIW"        "HBRED HIG"������������"NOR"       "HBRED HIG"������������\n"NOR;       
    msg += HIM"ֻ��$N���г����ڿ��л��˸��뻡��"HIG"���һ�ޡ�"HIM"ֱɨ��$n��\n"NOR;

    k1=(int)me->query_skill("hellfire-whip", 1);      
    mypot = k1 * k1 * k1 / 10 + ap;        

    if (random(mypot + dp) > dp * 3 / 5)
    {              
        damage = k1 + random(k1) + me->query("force_factor") + 100;
        msg += HIC"���$n��"HIG"���һ�ޡ�"HIC"ɨ����������ʹ���̣�\n"NOR;
        message_vision(msg, me, target);                                                                     

        target->receive_damage("kee",damage,me,"pfm");
        target->receive_wound("kee",damage/2,me,"pfm");
        COMBAT_D->report_status(target);                                 
    }
    else
    {
        msg +="���Ǳ�$nȫ�㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);       
    }

    msg = HIW"     \n"NOR; 
    msg += HIW"        "HBYEL+HIG"������������"NOR"       "HBYEL+HIG"������������"NOR"\n"NOR;      
    msg += HIW"        "HBYEL+HIG"��   "NOR+BLINK+HIR"ɱ"NOR+HBYEL+HIG"   ��"NOR"       "
        HBYEL+HIG"��   "NOR BLINK HIR"��"NOR+HBYEL+HIG"   ��"NOR"\n"NOR;
    msg += HIW"        "HBYEL+HIG"������������"NOR"       "HBYEL+HIG"������������\n"NOR;  
    msg += HIY"ֻ��$N�������������򳤱޹�ע������"+HIC"��ʱ��ֱ�����"+HIM"����ɥ����"
        HIY"��������ֱ����$n��\n"NOR;

    k2=(int)me->query_skill("kusang-bang",1);      
    mypot=k2*k2*k2/10 + ap;        
    if (random( mypot+ dp) > dp*3/5 )
    {              
        damage = k2+random(k2)+me->query("force_factor")+200;
        msg += HIC"���$n"+HIC"��ɨ�����ţ�\n"NOR;
        message_vision(msg, me, target);                                                                      
   
        target->receive_damage("kee",damage,me,"pfm");
        target->receive_wound("kee",damage/2,me,"pfm");
        COMBAT_D->report_status(target);
    }
    else
    {
        msg +="$n����ıܿ��ˡ�\n"NOR;
        message_vision(msg, me, target);       
    }
     
    msg = HIW"     \n"NOR; 
    msg += HIW"        "HBWHT+HIG"������������"NOR"       "HBWHT+HIG"������������"NOR"\n"NOR;      
    msg += HIW"        "HBWHT+HIG"��   "NOR+BLINK+HIR"ն"NOR+HBWHT+HIG"   ��"NOR"       "
        HBWHT+HIG"��   "NOR BLINK HIR"��"NOR+HBWHT+HIG"   ��"NOR"\n"NOR;
    msg += HIW"        "HBWHT+HIG"������������"NOR"       "HBWHT+HIG"������������\n"NOR;  
    msg += HIG"$N���г����罣������$n���ؿڣ���ʱ�ٹ��뺿������������ԭ������"+HIB"��׷�꽣��"
        HIG"��\n"NOR;

    k3=(int)me->query_skill("zhuihun-sword",1);      
    mypot=k3*k3*k3/10 + ap;        

    if ( random( mypot+dp ) > dp*3/5 )
    {              
        damage = k3+random(k3)+me->query("force_factor")+300;
        msg += HIC"���$n"+HIC"���޷�����������ֱ͸�ز���\n"NOR;
        message_vision(msg, me, target);   
        target->receive_damage("kee",damage,me,"pfm");
        target->receive_wound("kee",damage/2,me,"pfm");
        me->receive_damage("kee",10);
        COMBAT_D->report_status(target);
    }
    else 
    {
        msg +="���Ǳ�$n�͵�һ�ɣ��㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);       
    }


    me->add("force",-300);
    me->start_busy(2);

    return 1;
}


