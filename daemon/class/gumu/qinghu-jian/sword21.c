// shengling-sword ����ʮһʽ

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,lvl;
        int i;
        object weapon,ob;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ʮһʽ����̫�����ײ�Ҫ���á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("��Ȼ����ʮһʽ�ǽ������ˣ���Ҳ�����治�ý�ѽ��\n");
        if(me->query("family/family_name")!="��ԯ��Ĺ")
return notify_fail("������ʮһʽ��ֻ��ʥ�齣���˲ſ����ã�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("����ʮһʽ���ǽ�����ѧ��\n");
              if( (int)me->query_skill("qinghu-jian", 1) < 250) 
              return notify_fail("���������ȼ�̫�ͣ��޷�ʹ������ʮһʽ��\n"); 
        if ( (string) me->query_skill_mapped("sword") != "qinghu-jian")
        return notify_fail("�����������������޷�ʹ�ý���ʮһʽ\n");
        if (me->query_skill_mapped("force")!="jiuyin-force")
                return notify_fail("ֻ�о����澭��������˻���������\n");
        if((int)me->query("force") < 800 )
                return notify_fail("�������������\n");
        if((int)me->query("kee") < 400 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        if((int)me->query("sen") < 400 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        extra = me->query_skill("qinghu-jian",1) / 15;
        extra += me->query_skill("kongming-steps",1) / 15;
        me->add_temp("apply/attack", extra*3);    
        me->add_temp("apply/damage", extra*3);
        me->receive_damage("kee", 100);
        msg = HIW  "$Nһ˦�֣������б���������գ�������������������������������
        \n"HIY"
ֻ��$N�εض�������"+ weapon->name() +HIY"������һ���ޱ߽����������$n��\n\n" NOR;
        message_vision(msg, me, target);
           target->start_busy(1);
        msg =  HIW"ʥ�齣��ѧ����ʮһʽ\n\n" NOR;
        message_vision(msg, me, target);
        me->clean_up_enemy();
        ob = me->select_opponent();
                lvl=extra;
    if(lvl>3) lvl =21;
        for(i=0;i<lvl;i++)
        {
        msg = HIW "$N�������������潣�ߣ�ƮȻһ��Ϯ����\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
        }
        me->add_temp("apply/attack", -extra*3);
        me->add_temp("apply/damage", -extra*3);
        me->start_busy(random(extra/4));
        me->receive_damage("sen", 200);
        me->add("force", -400);
        me->receive_damage("kee", 200);
        return 1;
}

