#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,damage;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");

        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ"))
                      return notify_fail("����Ƿ���ô���÷��Ų���֮�ܣ�\n"); 

        if((int)me->query("max_force") < 800 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("force") < 200 )
                return notify_fail("����������㣡\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("lunhui-zhang",1)+me->query_skill("staff",1)/2;
        j=(int)me->query_skill("lunhui-zhang",1);

        if(i<60 || j<10)        
                return notify_fail("����ֻ��ȼ��𻹲�����ʹ����һ�л������ѣ�\n");
        
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIY"\n$N���з�ţ���ǧ����Ϊע������"+weapon->name()+NOR+HIY"��ʱ��ϼ�����䣬�յ�$n�������ۣ�\n"NOR,me,target);
        message_vision(HIW"\n                    ��������������� \n"NOR,me,target);
        message_vision(HIC"\n�Ҳ��������˭���������Ω��������ҳ�ס������
��Ω��ס����������ׯ�ϵ������뷢����Ը��������δ�գ��Ĳ��ɷ���
���Ⱦ�����֤���ᡣ\n"NOR,me,target);
        
        damage=me->query_skill("buddhism") + me->query_skill("staff") +                me->query_skill("lunhui-zhang") + me->query("max_force");

        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) 
        {
                target->receive_damage("kee",damage/3,me,"cast");
                me->receive_damage("sen", 100+random(50),me,"cast");
                me->receive_damage("kee", 100+random(50),me,"cast");
                COMBAT_D->report_status(target);
                COMBAT_D->report_status(me);            
                
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

