// mantian.c ��ϼ����
// ����ǳsword ��Ч�ȼ�180��ʱ�����������Լ����б��������齣Ϯ��
// �������sword ��Ч�ȼ�180��ʱ���Ϳ���ʩչ��蚣����齣��
// ���������н��������������call_out("perform_qiao", 10, me)
// �ý���ɱ�ˣ����������С������ļ�/d/pansi/obj/qiao
// daemon/class/pansi/qingxia-jian/mantian ��ϼ����
// jie 2001-2-4
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp,kee_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("sword");
        skill2 = me->query_skill("force");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��������ʹ����ô��ʹ����ϼ���졹��\n");

        if((string)weapon->query("name") == "����")
                return notify_fail("ɵ�ϣ�������ô�Ƶ��飿\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("����ϼ���졹ֻ����ս����ʹ�á�\n");
        if (!PFM_D->valid_family(me, "��˿��"))
                          return notify_fail("����ϼ���족ֻ����˿�����˲ſ����ã�\n");


        if( (int)me->query("max_force") < 600 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("force") < 300 )
                return notify_fail("�����ڵ��������㣡\n");

        if( skill < 100)
                return notify_fail("����ϼ��������Ϊ����������ʹ�á���ϼ���졹! \n");

        if( skill2 < 90)
                return notify_fail("������ľ�����Ϊ����������ʹ�á���ϼ���졹! \n");

        if( me->query_skill_mapped("sword") != "qingxia-jian") 
                return notify_fail("��û�м�����ϼ�������޷�ʹ�á���ϼ���졹��\n");

        if( time()-(int)me->query_temp("mantian_end") < 3 )    
                return notify_fail(CYN"�����ö��˾Ͳ����ˣ�\n"NOR);    
 
        if (skill<180 && me->query_str()>100)
        {
                msg = HIY "$N��Ȼ���������������������ὣ����ʱ�������ѣ����磭��
                \n"HIC"����ϼ���졻
                \n"HIY"����������Ƭ����ǵ���$n�����ȥ��\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
// �������װ���Ĳ������౦������ô���еĽ���û��
// ע����������౦��d/pansi/obj/ziqing.c�ļ��в���
// set("no_break", 1);                
        if( (string)weapon->query("id")!="ziqing sword")
                destruct(ob);
 
                ap = ((me->query("combat_exp"))*(me->query_spi()));
                dp = ((target->query("combat_exp"))*(target->query_spi()))/3;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$n��ǰ�·�ӿ��������ɫϼ�⣬���֮�£�������Ƭ��ȻǶ����$n�����ϣ�\n\n$n�ҽ�һ��������¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 80 + skill + random(skill*2);

                        if(kee_wound > target->query("kee")) kee_wound = (target->query("kee") + 1);
                       
                        target->receive_damage("kee",kee_wound,me,"pfm"); 
                        target->receive_wound("kee", kee_wound/2,me,"pfm");
                       
                        COMBAT_D->report_status(target, 0);
//                        me->start_busy(1+random(1));
                        me->add("force",-100);
                }
                else
                {
                        msg = HIG "ֻ��$n���ҵ�������һ��ؼ��ɳ��죬���������������Ľ�Ƭ��\n\n"NOR;
                        message_vision(msg, me, target);
//                        me->start_busy(2);
                        me->add("force",-50);
                }

                call_out("perform_qiao", 10, me);
                me->set_temp("mantian_end",time());
                return 1;
        }
        else if(skill<180 && me->query_str()<100 )
        {
                msg = HIW "$N��Ȼ���������������һ���Ҫʩչ��ϼ�������Ͼ���֮һ�ġ���ϼ���족��
                \nȴ���Ϲ������㣬��Ȼû����������"+weapon->query("name")+HIW"��\n" NOR;
                msg += HIR "$n��Ҫ������ͻȻ���ֻ����ѵã���ʱ������������\n\n";
                message_vision(msg, me, target);
                me->add("force",-50);
//                me->start_busy(1+random(2));
        }
        else
        {
                msg = HIW "$NͻȻ���������������"+weapon->query("name")+HIW"�����罣â���£�����һ��\n��Ȼʹ������ϼ�����ܴ�����
\n"HIC"��������ϼ��â������
\n\n"HIW"��㽣â�����ӿ���������壬��������������$n��\n\n" NOR;
                message_vision(msg, me, target);

//                ap = (me->query("combat_exp"))*(me->query_spi());
                ap = me->query("combat_exp");
//                dp = (target->query("combat_exp"))*(target->query_spi())/3;
                dp = target->query("combat_exp")/3;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$n�Ը�������Ȼ�����޲ߣ������âǡ��������Ƭ������$n�����ϣ�\n\n$n�ҽ�һ��������¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 80 + skill + random(skill*2);

                        if(kee_wound > target->query("kee")) kee_wound = (target->query("kee") + 1);
                        target->receive_damage("kee",kee_wound,me,"pfm"); 
                        target->receive_wound("kee", kee_wound/2,me,"pfm");
                        COMBAT_D->report_status(target, 0);
//                        me->start_busy(1 + random(1));
                        me->add("force",-100);
                }
                else
                {
                        msg = HIG "$n��Ȼ������������һ��ؼ��ɳ��죬���������������Ľ�â��\n\n"NOR;
                        message_vision(msg, me, target);
//                        me->start_busy(2);
                        me->add("force",-50);
                }

                me->set_temp("mantian_end",time());
                return 1;
        }

        return 1;
}
int perform_qiao(object me)
{
        object weapon, target;
        target = me->select_opponent();
        if(me->is_fighting() && living(target) && living(me) && (!objectp(weapon = me->query_temp("weapon"))))
        {
                object qiao;
                string msg;
                int count;
                qiao = new("/d/pansi/obj/qiao");
                qiao->move(me);
                qiao->wield();
                count = me->query_spi();
                me->add_temp("apply/dodge", count * 3); 
                count = me->query_str();
                me->add_temp("str", count * 2); 
                msg = HIY "\n$NͻȻ�����Ͻ������õ����У���ʽͻȻ���٣�����㹥�����У���ͻȻ�ı仯��$nĿ�ɿڴ���\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->delete_temp("apply/dodge", count * 3);
                me->delete_temp("str", count * 2);
        }
        return 1;
}
