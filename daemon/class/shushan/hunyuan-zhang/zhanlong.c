//fumozhang perform ն����
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int myexp, yourexp, myskill, yourskill;
        int ap, dp, damage, def;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIY"��ն������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail(HIW"�㲻����ɽ�ɵ��ӣ������ˡ�ն�������ľ�Ҫ��\n"NOR);
        if( (int)me->query_skill("hunyuan-zhang",1) < 100)
                return notify_fail(HIW"��Ļ�Բ�ƻ���������!\n"NOR);
        if( (int)me->query("force") < 300)
                return notify_fail(HIW"�������������!\n"NOR);
        if( (int)me->query("max_force") < 800)
                return notify_fail(HIW"�������̫��,��ն����������ȥҲû��������\n"NOR);


        msg = HIR
"\n$N��ȻһЦ,һ����Х����ָ�罣����Ȼ���ּҵľ���--��ն������������$n������ȥ��\n" NOR;
        myexp= me->query("combat_exp") /900;
        yourexp=target->query("combat_exp")/1000;

        myskill=me->query_skill("hunyuan-zhang",1);
        yourskill=target->query_skill("dodge");
        ap=myexp*myskill;
        dp=yourexp*yourskill;
        if (random(ap+dp)>dp)
        {
                msg += HIW
"\nֻ���׹�һ����$n�������Ѿ���һɨ����!\n" NOR;
                damage=(int) me->query("max_kee")/2;
                def=(int)target->query_temp("apply/armor_vs_force");
                damage -=damage*def/3000;
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                if(me->query_temp("shushantop")) target->start_busy(2);
                //me->start_busy(random(2)+1); 
                me->start_busy(1); 
        }
        else 
        {
                msg += HIW "$n��Цһ��:�����΢ĩ֮�������ҺΣ���\n" NOR;
                me->start_busy(random(2)+1);


        }
        if( wizardp(me) && (string)me->query("env/combat")=="verbose" )
                tell_object(me, sprintf( GRN "AP��%d��DP��%d���˺�����%d\n" NOR,
                                ap/100, dp/100, damage));

        message_vision(msg, me, target);
        return 1;
}


