//��ħ����
//modify by Wuyou@Sanjie

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object *inv, obj;
        object weapon;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ħ��������\n");

        if(!me->is_fighting())
                return notify_fail("����ħ������ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ"))
                return notify_fail("�㻹û���Ĵ�Կա���������������ħ������\n");

        if((int)me->query("max_force") < 2000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("����ֻ��ȼ��𻹲�����ʹ����һ�л������ѣ�\n");
                
        if( time()-(int)me->query_temp("xiangfu_end") < 3 )  
                return notify_fail("�����Ϣ��δƽ���������ٴ�ʹ����ħ������\n");                

        message_vision(HIY"$N�����"HIW"����հ��������۾���"HIY"��\n"NOR,me,target);
        message_vision(HIY"\n\t������ȼ������������������ģ��ռ�һ�С�\n"NOR,me,target);
        message_vision(HIY"\tԸ���������������࣬�����������Ͼ����֡�\n"NOR,me,target);
        message_vision(HIY"\t�������࣬����������������࣬����������\n"NOR,me,target);
        message_vision(HIY"\t�������ģ�Ը�����ţ�����������δΪʤҲ��\n"NOR,me,target);
        message_vision(HIY"\t֪��˵�����緤���ߣ�����Ӧ�ᣬ�ο��Ƿ���\n"NOR,me,target);
        message_vision(HIY"\t�������������سɷ𣬷�˵������������!\n"NOR,me,target);
//      message_vision(HIR"\n$N���е�"+weapon->query("name")+HIR"��������ϼ�⣬ֻ�������������$n����\n"NOR,me,target);
        message_vision(HIY"\n        ����"HIR"��������"HIW">>>>><<<<<"HIR"��ħ����"HIY"����\n"NOR,me,target);
        
        mystr=(int)me->query("str");
        tastr=(int)target->query("str");
        myexp=(int)me->query("combat_exp")/20;
        taexp=(int)target->query("combat_exp")/30;
        mylvl=(int)me->query_skill("staff")+(int)me->query_skill("lunhui-zhang");
        talvl=(int)target->query_skill("parry")+(int)target->query_skill("dodge");
        mypot=mystr*mylvl+myexp;
        tapot=tastr*talvl+taexp;
        y=random(3);
        if( mypot >tapot/2+random(tapot)/2) 
        {
                message_vision(HIY"\n$N���۳ճտ���Զ������ʶ�����ܵ��˷���ٻ�,�ƺ�ɱ��ȫ�ޣ���Ȼ�����˲�������...\n\n"NOR, target);
                
                target->receive_damage("kee", 200 + random((int)me->query("max_force")/4+(int)me->query("max_force")/10+(int)me->query("force_factor")),me,"pfm");
                target->receive_damage("sen", 200 + random((int)me->query("max_mana")/4+(int)me->query("mana_factor")),me,"pfm");    
                target->receive_wound("kee", 100 + random((int)me->query("max_force")/4+(int)me->query("max_force")/10+(int)me->query("force_factor")),me,"pfm");
                target->receive_wound("sen", 100 + random((int)me->query("max_mana")/4+(int)me->query("mana_factor")),me,"pfm");    

                COMBAT_D->report_status(target);
                COMBAT_D->report_sen_status(target);         
                
        }
        else 
        {
                message_vision(HIG"˭֪$N"HIG"��Ȼȫ�޸о�������ɱ��ȴԽ��ԽŨ��\n"NOR, target);
        }
        
        me->add("force", -200);
        me->receive_damage("sen", 60);
        me->set_temp("xiangfu_end",time());

        return 1;
}

