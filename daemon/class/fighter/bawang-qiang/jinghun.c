//�������ǹ BY Cigar 2002.04.05

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon; 
        int damage, ap, dp;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"��Ҫ��˭ʩչ���������ǹ����\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"���������ǹ��ֻ����ս����ʹ�ã�\n"NOR); 
        
        if (!PFM_D->valid_family(me, "������"))
                return notify_fail(CYN"�㲻�ǽ�����֮�ˣ�����͵ѧ���ľ�����\n"NOR);
        
        if((string)me->query_skill_mapped("force")!="lengquan-force")
                return notify_fail(CYN"���������Ȫ�񹦡�\n"NOR);

        if((int)me->query("force") < 150+(int)me->query("force_factor") )
                return notify_fail(CYN"����������㣬�ô��п��»���Σ�ա�\n"NOR);

        if(me->query("max_force") < 1000 || me->query("force")<500)
                return notify_fail("���������Ϊ��ǳ����������[�������ǹ]��\n"NOR);

        if((int)me->query("kee") < 200 )
                return notify_fail(CYN"������̫�����ˣ��޷�ʩչ���������ǹ����\n"NOR);

        if( time()-(int)me->query_temp("jinghun_end") < 3 ) 
                return notify_fail(CYN"�����ھ����޷����У����ô˾���������Ԫ����\n"NOR); 
        
        if((int)me->query_skill("bawang-qiang", 1) <120)
                return notify_fail(CYN"��İ���ǹ���������죬�޷�ʹ�����С��������ǹ����\n"NOR);

        if((int)me->query_skill("lengquan-force", 1) <120)
                return notify_fail(CYN"�����Ȫ��������ǳ������ʹ�����������ǹ����\n"NOR);

        me->add("force", -65-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        msg = HIW "\n$N�־�"+ weapon->query("name")+ HIW"ֱָ����,ֻ��ǹͷ������,ǹӧ��ʱ�Ե÷�����次�";
        msg += "\n\n˵ʱ�٣���ʱ�죬$N˫�������������գ�����ͣ�٣���תǹͷ��������������һ���֡�\n\n" NOR;
        
        msg +=HIY "              ������                        ������  \n";       
        msg +=HIY "              ��"+HIW"�@"+HIY"��  ��������������������  ��"+HIW"��"+HIY"��  \n";
        msg +=HIY "              ��"+HIW"��"+HIY"��  ��"+HIR" �@ �� �� �� �� "+HIY"��  ��"+HIW"��"+HIY"��  \n";
        msg +=HIY "              ��"+HIW"��"+HIY"��  ��������������������  ��"+HIW"��"+HIY"��  \n";
        msg +=HIY "              ������                        ������  \n";
// ������ msg +=HIW"��ʽ"+HIR"�������ǹ"+HIW"���������ڻ��˰ټ�֮����ʵ�Ǿ�ѧ�еľ�����\n" NOR;
        ap = me->query_skill("bawang-qiang", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/200) <  dp/1000 ) 
        {
                msg += "\n\n$n"+HIC"���弱�ٺ��ˣ��������ĵĶ������������һ�У���ʱ���������亹���졣\n\n"NOR;
                message_vision(msg, me, target);
//              me->start_busy(1+random(1)); 
        } else {
                damage = (int)me->query_skill("parry",1) / 10 +
        (int)me->query("sen") / 400 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 400 + random((int)me->query("kee") / 200 );
                msg += HIW "\n\nֻ������һ����$N���弸����վ����Զ��ɽ�о��£�����$n��ǰ�Ѿ����̳�һ��Ѫ������\n\n" NOR;
                damage +=random(50);
                if(!target->is_busy()) target->start_busy(2);
                target->receive_damage("sen", me->query("eff_sen")*damage/250,me,"pfm");
                target->receive_damage("kee", me->query("eff_kee")*damage/180,me,"pfm");
                target->receive_wound("kee", me->query("eff_kee")*damage/200,me,"pfm");
                me->improve_skill("bawang-qiang", 1, 1);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
//        me->start_busy(2);
        me->set_temp("jinghun_end",time()); 
        return 1;
}

