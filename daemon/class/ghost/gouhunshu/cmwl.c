//��������
//cast cmwl ,hell gouhunshu
// modify by shao 2001.12.28
//�Ĵι���������󹥻�
//��dx,skills�й�

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, dx1,dx2,skills1,skills2,spi,mana1,mana2;

        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail("�ǹ��岻���ٻ��������ˡ�\n");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ���ʲô��\n");

        dx1=(int)me->query("daoxing",1);
        dx2=(int)target->query("daoxing",1);
        skills1=(int)me->query_skill("spells",1);
        skills1=skills1*skills1*skills1/10;
        skills2=(target)->query_skill("spells",1);
        skills2=skills2*skills2*skills2/10;
        spi=(int)me->query_spi();
        mana1=(int)me->query("mana",1)+(int)me->query("max_mana",1);
        mana2=target->query("mana",1)+target->query("max_mana",1);
         
        if((int)me->query("mana") < 300+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 400 )
                return notify_fail("��ľ���̫���޷�ʩչ������\n");

        if((int)me->query_skill("gouhunshu",1) < 100)
                return notify_fail("�����ˮƽ����ڤ����ʥ�� \n"); 

        me->add("mana", -200-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 100 ) {
                write("������ʥ�����Ź��ȥ�ˣ����ڼң�\n");
                return 1;
        }

        msg = HIC
"$N���������дʣ������һ������ڤ����ʥ----�������˺��ڣ�\n
ֻ��һ���ڹ�������һ����òһ��Ĵ�ͷ��----�ι���$nײȥ��\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/4 ) {
                target->receive_damage("kee", 200, me, "cast");
                target->receive_wound("kee", 100, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//��һ�ι���

        msg = HIC
"����һ����ò���Ĵ����----�ȹ���$nҧȥ��\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/4 ) {
                target->receive_damage("kee", 200, me, "cast");
                target->receive_wound("kee", 100, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//�ڶ��ι���

        msg = HIC
"���һ����òƽƽ�Ĵ��ֹ�----�͹���$nץȥ��\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/3 ) {
                target->receive_damage("kee", 300, me, "cast");
                target->receive_wound("kee", 200, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//�����ι���

        msg = HIC
"���һ����òӢ���Ĵ�Ź�----�˹���$n��ȥ��\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/3 ) {
                target->receive_damage("kee", 300, me, "cast");
                target->receive_wound("kee", 200, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//���Ĵι���

       if (random(dx1+skills1) > (dx2+skills2)*2/3 ) {
                msg = HIB
"$n�ո�һ��и��ֻ���Ĺ��һ���ƺ���һ������Ի������뺿����$nֻ����
˫����������ǰ���ڣ� \n" NOR;
                message_vision(msg, me, target);
                damage=mana1-mana2+spi*20;
                if (damage < 400 )
                damage = 400;
                me->add("mana",-200);
                target->start_busy(4);
                target->receive_damage("kee", damage, me, "cast");
                target->receive_wound("kee", damage, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//�����

        if( !target->is_fighting(me) )  
        { 
                if( living(target) )  
                { 
                        if( userp(target) ) target->fight_ob(me); 
                        else me->kill_ob(target); 
                } 
        } 

//       me->start_busy(2);
       return 3+random(2);

}


