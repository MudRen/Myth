#include <ansi.h>

inherit SSERVER;
//inherit F_CLEAN_UP;

string get_name(string str)
{
        str="����";
        return str;
}

string get_help(string str)                
{
        str="ָ�����������������\n"
        +"����������ǹ��100����ƽ���100��"
        +"�����ʼ��ߵľ��У�������С��";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int i,j,k,damage;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");
                
        if (!PFM_D->valid_family(me, "���ƶ�"))
                return notify_fail("�����ڡ�ֻ�л��ƶ����˲ſ����ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("����ڹ�̫�\n");

        if( time()-(int)me->query_temp("buhui_end") < 2+random(2))    
                return notify_fail(CYN"�����ڡ����������̫��,�޷�����ʹ�ã�\n"NOR); 
        if( time()-(int)me->query_temp("qianghun_end") < 3 ) 
                return notify_fail(CYN"�����ڡ��롸����ǹ�꡹�޷�����ʹ�ã���\n"NOR);                     
        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("pingtian-dafa", 1) < 100)
                return notify_fail("���ƽ��󷨵ȼ�����������ʹ����һ�У�\n");
                
        i=(int)me->query("combat_exp");
        j=(int)target->query("combat_exp");
        k=(int)me->query_skill("spear");
        
        if(k<100)        
                return notify_fail("���ǹ�����𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIM"\n$Nһͦ����"+weapon->name()+NOR+HIB"ֱ��$n��\n"NOR,me,target);
//���ƶ������400skills֮ǰ������ǹ�꣬һֱ��Թ��������������
//���Ժݺݵļ�ǿ�˲��ڡ�
//Wuyou@Sanjie
        //if (random(i)>random(j)) 
        if (i > random(j)) 
        {
                damage=k+(int)me->query("str");
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/5,me,"pfm");
                COMBAT_D->report_status(target);
        }
        //if (random(i)*7/8> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���"+HIB"$n"+HIM"��\n"NOR,me,target);
                damage=k+random(k)+(int)me->query("str");
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/5,me,"pfm");
                COMBAT_D->report_status(target);
        }
        //if (random(i)*5/6> random(j)) 
        if (i > random(j)) 
        {
                message_vision(CYN"\n$Nһǹ�̿գ�����һ�⣬����δ�����Ի���"+HIB"$n"+CYN"��\n"NOR,me,target);
                message_vision(HIM"\n$Nһ���ֿգ����Բ����У�˫��һ�ɣ�һͷײ��"+HIB"$n"+HIM"��\n"NOR,me,target);
                damage=k+random(k)*2+(int)me->query("str");
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/5,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
                if (random(2)) 
                {
                        message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
                        message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
                        message_vision(HIM"\n$Nһͷ��Ȼײ�գ���$nҲ����ƴ���ľٶ�����һ����\n"NOR,me,target);
                        target->start_busy(5);
                }
                else 
                {
                        message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
                        message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
                        message_vision(HIW"\n$n������Ц��ֻ��ƥ��ֻ�����к��ã����ɱܿ�\n"NOR,me,target);
                }

        me->receive_damage("sen", 50);
        me->add("force", -100-(int)me->query("force_factor"));
        me->receive_damage("kee", 30); 
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->set_temp("buhui_end",time());    
        return 1;
}


