//���������,����޷�lestat/2001.2.14
// modi by xintai 3/2/2001
//koker 10/3/2001

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int mjianb, mjianh, tparryb, tparryh, mneili, tneili, mexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        mjianb= (int)me->query_skill("whip",1);
        mjianh= (int)me->query_skill("yirubian",1);
        mneili = (int)me->query("force");
        mexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="whip")
                return notify_fail("���ñ�����ʹ����������¡���");
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("�������ңһ���ϵ��û�У�ʹ�������У�\n");
        if ( mjianh < 120) return notify_fail("�������޷����������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������¡�ֻ����ս����ʹ�á�\n");
        if ((int)me->query("force")<300)
                return notify_fail("�������������\n"); 
        tweapon = target->query_temp("weapon");  //  Here might be wrong, need to check.
        tparryb= (int)target->query_skill("parry",1);
        tneili = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
        
        message_vision(HIC"$N��ʽһ�䣬����"+weapon->name()+HIC"бָ���£�˫��ĮȻ��һ��������������̬��ȴʹ������ɽ�ľ�ѧ--����������¡���\n\n" NOR,me,target);        
        message_vision(HIM"$N��ǰ��һ����ƽ�޻��ػӳ�һ�ޣ�����ȴ��ž���졣\n"NOR,me);
        message_vision(HIM"��һ�С������ƴ����������\n\n"NOR,me);
        if (random(mexp)>(int)(texp/11) && random(mneili) > (int)(tneili/4)&&
          (int)me->query("max_force")+mneili > (int)target->query("max_force") + tneili) 
        {
                msg = HIC"$nֻ����һ�ɾ�������ǧ��öϸ��һ�������������\n"
                                "���ۡ���һ����$n���һ�����Ѫ���������������ˣ�\n\n"NOR;
                damage= (int)(((int)me->query("max_force")-  (int)target->query("max_force")/2)/3);
                if(damage<1)damage = 1;
                target->receive_damage("kee",damage*2, me, "pfm");
                target->receive_wound("kee", damage*2/3, me, "pfm");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg = HIC"$næ�˹��򿹣�����������$N�������Ӱ����ɢ�ˡ�\n\n"NOR;
                message_vision(msg, me, target);
        }

        message_vision(HIM"$N�ɾ�ת����һ���㼱��磬��̤���ţ��������У�ÿһ�޴�$n���벻���ķ�λ������Ϣ�ػӳ���\n" NOR,me,target);
        message_vision(HIM"��һ�С���ʸ���Ρ������Ǳ޷���\n\n" NOR,me,target);
        if(random(mexp*2)>(int)(texp/11)&& random((int)(mjianb + mjianh*3))>(int)((tparryb+tparryh)/4))
        {
                msg = HIC"$n������æ���ң���֪�����ȥ�м��⾲����ڤ�������ı޷���\n"
     "����Ȼ��$N��"+weapon->name()+HIC"�������У�$n�������±���ñ������ˣ�\n\n"NOR;
                damage=random(100)+me->query("force_factor");
                if(damage<1)damage = 1;
                target->receive_damage("kee", damage*2, me, "pfm");
                target->receive_wound("kee", damage*2/3, me, "pfm");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }
        else
        {
                msg = HIC"$nȴ�ľ���ˮ��˿�����Ի��ң����в��У��߽���$N�������Ĺ��ơ�\n\n"NOR;
                message_vision(msg, me, target);
        }


        message_vision(HIM"$NͻȻ��ס���Σ��ز��������ձ��ڱ�������ʤ���У�����ʤ���Ρ�\n"NOR,me);
        message_vision(HIM"��һ�С�������ԡ��ȵ��Ǿ��飡\n\n"NOR,me);
        if(random(mexp)>(int)(texp/4))
        {
                msg = HIC"$n��Ȼ�ϵ�����Ϊ$N¶����������ϲ֮�£���æ��ǰ��������\n"
          "$N΢΢һЦ����$n����������һ�����価�޳���ֱ̽$n���ؿڡ�\n"
          "$n����Ӱ��û�������Ͳ���������͸������\n\n"NOR;
                damage=(int)(random((int)(mjianh/2))+me->query("force_factor")*3/2);
                if(damage<1)damage = 1;
                target->receive_damage("kee", damage*2, me, "pfm");
                target->receive_wound("kee", damage*2/3, me, "pfm");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }
        else
        {
                msg = HIC"$n���������е���ʵ�����ƾͼƣ���װ����ǰ��ȴ��$N���е�һ˲���ڿն��𣬻��־�����һ�У�\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(2);
           
        return 1;
}


