//yudian 2000-11-14
// haotan.c  �����̾  
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
                return notify_fail("û��Ը�������߿ࡣ\n");
        if( !me->is_fighting(target) )
                return notify_fail("����ս���У����ǵ���������ο�ɡ�\n");
        if (!present("wuxian qin", me))
                return notify_fail("�������̾����������������ϲ���ʹ�á�\n");
        if (!PFM_D->valid_family(me, "��˿��"))
return notify_fail("�������̾��ֻ����˿�����˲ſ����ã�\n");
        if (me->query_skill_mapped("force")!="jiuyin-xinjing")
                return notify_fail("ֻ���þ����ľ������ס�\n");
        if (me->query_skill("chixin-jian",1)<50)
                return notify_fail("��ĳ����鳤����������������\n");
        if (me->query_skill("qin",1)<50)
                return notify_fail("�����յĹ��򻹲������ٺú������ɡ�\n");
/*
        if (target->query_skill("literate",1)<50)
                return notify_fail("���Ǹ����ˣ�������Щ��Ů���¡�\n");
*/
        if((int)me->query("force") < 100 )
                return notify_fail("����������������\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("��������Ѿ������ˣ�\n");
	if((int)me->query("sen") < 150 )
                return notify_fail("�����Լ������Ʋ�ס�Լ��ĸ��飡\n");
        msg = HIC "\n$N��ס"+weapon->query("name")+HIC"���ȶ����������Ʋ��������ⲻ����\n" NOR,
        msg += RED "\n$N���������ͳ�"+HIB"������"NOR+RED"����Ȼ�͵���ϥ��������"+weapon->query("name")+RED"Ϊָ���������ң�����$n������̾��\n" NOR,
        msg += HIM "\n���˺������޾��ڡ�������̾Ϣ�����ư�Թ�������������������Ǹ�©����������Ϩ��\n\n" NOR,
        me->add("sen", -150);
        me->add("kee", -150);
        me->add("force", -150);
        ap =(int)me->query_skill("chixin-jian", 1) +(int)me->query_skill("qin", 1)
            +(int)me->query_skill("literate", 1);
        damage=ap*ap/1000;
        ap = ap/10 * ap * ap;
        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("dodge")
             +(int)target->query_skill("literate")
             +(int)target->query_skill("spells");
        dp = dp/100 * dp * dp;   
        dp = dp + (int)target->query("combat_exp");
        if( random(ap) <  dp*1/3 ) 
{
             msg += HIW "$n������������Ц��������������ģ��������黹����˼˵����"
                        +"$N��ʱ�����ѵ���\n"NOR;
             message_vision(msg, me, target);
             me->start_busy(2);
            } 
        else if( random(ap) <  dp*2/5 ) 
            {
             msg += HIW "��$n������ţ���Ϊ������\n"NOR;
             message_vision(msg, me, target);
             me->start_busy(1+random(2));
            } 
         else 
            {
             target->receive_damage("sen",damage,me,"pfm");
             target->receive_wound("sen", damage,me,"pfm");
             msg += HIM "$Nǰ��̾δ�����ֺ��ٺ�̾������Ȼ����δ��ʱ����\n��˳����̾��������ת������ҹĻ����ɢ������\n\n"NOR;
             msg += HIW "$nΪ������Ⱦ������˼�������������Ȼ����������\n"NOR;
             message_vision(msg, me, target);
             COMBAT_D->report_status(target); 
             target->start_busy(5+random(5));
             me->start_busy(1+random(2));
            }
          return 1;
}
