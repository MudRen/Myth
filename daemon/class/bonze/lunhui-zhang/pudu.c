// writted by jie
// 2/2001

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���ȹ��նɡ���\n");

        if(!me->is_fighting())
                return notify_fail("���ȹ��նɡ�ֻ����ս����ʹ�ã�\n");
        
        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ"))
                return notify_fail("���Ƿ��ŵ��Ӳ����á��ȹ��նɡ���\n");
        // ����ɱ���ߣ����󲻷�����ʵ�������趨��ɱ������
        if( (int)me->query("bellicosity") > 300 )
        return notify_fail("���ɱ��̫�أ��޷�ʩչ���ž�����\n");
                
        if (me->query_skill_mapped("force")!="lotusforce")
                return notify_fail("���ȹ��նɡ���������̨�ķ�Ϊ���ӣ�\n");
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");
        
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        
        if((int)me->query_skill("lotusforce", 1) < 80)
                return notify_fail("�����̨�ķ���Ϊ��������ʹ����һ�л������ѣ�\n");
        
        if((int)me->query_skill("lunhui-zhang", 1) < 80)
                return notify_fail("����ֻ�����Ϊ��������ʹ����һ�л������ѣ�\n");
        
        message_vision(HIY"$N������������ջ�����⣬��ת�������ھ��С��ȹ��նɡ�����$n��������������\n"NOR,me,target);
        
        me->set("ciguangpudu", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete("ciguangpudu");
        me->start_busy(2);
        message_vision(HIW"$N�����������ӷ𣡡����ȹ��նɡ��ù���ϣ����ϵ����Ľ��������ȥ.\n"NOR,me,target);

        me->add("force", -50);
        return 1;
}

