//yudian 2000-11-14
// zouxiao.c  ���ﴫ��  
//Changed by wuyou@sk

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg;
        object weapon;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭���\n");
        if( !me->is_fighting(target) )
                return notify_fail("��Ҷ���æ��û����ʱ�����㴵�����\n");
        if (!weapon || weapon->query("music/type") != "xiao")
                return notify_fail("������ļһﴵ�������ӡ�\n");
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("ֻ������Ԫ�񹦲����������\n");
        if (me->query_skill("xiaofeng-sword",1)<50)
                return notify_fail("���������½�������������\n");
        if (me->query_skill("zouxiao",1)<60)
                return notify_fail("������Ĺ��򻹲������ٺú������ɡ�\n");
/*        
        if (target->query_skill("literate",1)<50)
                return notify_fail("��������������ţ�����ء�\n");
*/                
        if((int)me->query("force") < 200 )
                return notify_fail("����������������\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("��������Ѿ������ˣ�\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("���޷����о�����\n");
        msg = HIW "\n$N����"+weapon->query("name")+HIW"������$n������һ��������������"
                  +"����̾Ϣ�����ƿ�����������������������ɪɪɪ����֮��������һ�ε�С��������Ҷ��\n" NOR,
/*        
        me->add("sen", -150);
        me->add("kee", -150);
        me->add("force", -150);
*/        
        me->add("sen", -50);
        me->add("kee", -50);
        me->add("force", -50);
        ap =(int)me->query_skill("xiaofeng-sword", 1)+(int)me->query_skill("zouxiao", 1);
        damage=ap*ap/300;
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("literate")
             +(int)target->query_skill("zouxiao")
             +(int)target->query_skill("fuqin")
             +(int)target->query_skill("spells");
        dp = dp * dp * dp /10;   
        dp = dp + (int)target->query("combat_exp");
        //if( random(100*ap/dp) <  20 ) 
        if( random(2000*ap/dp) <  20 ) 
        {
                msg += HIW "$n������������Ц��������㱾�£�Ҳ����Ц�󷽣�"
                        +"$N��ʱ�����ѵ���\n"NOR;
                message_combatd(msg, me, target, "");
                //me->start_busy(3+random(5));
                me->start_busy(2+random(1));
        } 
        else if( random(2000*ap/dp) <  40 ) 
        {
                msg += HIW "��$n������ţ���Ϊ������\n"NOR;
                message_combatd(msg, me, target, "");
                me->start_busy(random(2));
        } 
        else 
        {
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen",damage,me,"pfm");
                msg += HIW "$n��������������Ī������ĸе�һ�������������������ˮ�������¡�\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->report_sen_status(target); 
                target->start_busy(5+random(5));
                me->start_busy(random(2));
        }
        return 1;
}


