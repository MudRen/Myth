#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int  myexp, yourexp,i,num,damage;
        object weapon;
     
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ý�âֻ����ս����ʹ�á�\n");
        if((int)me->query_skill("sanqing-jian",1) < 80)
                return notify_fail("������彣���ȼ���������\n");
        if(me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("��â��Ҫ��Ԫ�񹦵�֧�֡�\n"); 
        if( (int)me->query("max_force") < 800)
                return notify_fail("�������̫��,�����³���â��\n");
        if( (int)me->query("force") < 400)
                return notify_fail("������������ˣ�\n");
        if (!PFM_D->valid_family(me, "��ׯ��"))
                return notify_fail("[��â]����ׯ�۾������ڣ��㲻��ׯ��֮�ˣ����ܷ�����\n");
        if(me->query_temp("jianmang_busy"))
                return notify_fail("���ˣ���âû�з�����\n");
        myexp = (int)me->query("combat_exp");
        yourexp = (int)target->query("combat_exp");
        msg = HIC
        "\n$Nһ����Ц�����г���бָ���죬�����³�һ�ų������â���������԰�����������\n"
        "$n������䣬���Ž�âȴ�͵ñ��ǣ�����$n������ֱ�������\n\n" NOR;       
        message_combatd(msg, me, target, "");
        damage=me->query_temp("apply/damage")+me->query("force_factor");
        num=0;
        for (i=1;i<=6;i++) 
        {
                if( random(myexp)>random(yourexp))
                num++;
        }   
        if(num>0)         
        {
                damage=damage*num;
                
                if (!PFM_D->valid_family(me, "��ׯ��"))
                damage=damage/3;
                
                msg = HIR
                "\nֻ��$nһ���Һ�,��â��$n�Ķ�ͷ�ӹ�,����һ��Ѫ�⣡\n" NOR;

                msg += HIW
                "\n��â���羭�������ʴ�ת��һת,�ַɻ�$N����ߡ�\n" NOR;
                message_combatd(msg, me, target, "");
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
/*
                //if (random(damage)>target->query_temp("apply/armor"))
                if (damage>target->query_temp("apply/armor"))
                target->receive_wound("kee",damage-target->query_temp("apply/armor"),me,"pfm");
*/
                COMBAT_D->report_status(target,1);
                if(!target->is_busy()) 
                        target->start_busy(1+random(2));
                //target->kill_ob(me);
  
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);


        }
        else 
        {
                msg = HIY
                "\n$nȴʶ�����Ž�â������,����ԶԶ����һ�ߡ�\n" NOR;
                message_combatd(msg, me, target, "");
                me->start_busy(2);
        }
        me->add("force",-120);
        me->set_temp("jianmang_busy",1);
        call_out("jianmang_ok",2+random(2),me);
        return 1;
}

void jianmang_ok(object me) 
{
        if (!me) return;
        me->delete_temp("jianmang_busy");
}

