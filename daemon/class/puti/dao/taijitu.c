// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

//taijitu.c

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="̫��ͼ";
        return str;
}

string get_help(string str)                
{
        str="ָ���������������\n"
        +"��������������>=100������>=1000������>=500\n"
        +"�����ɷ��ľ��裬������ʱ�������ӹ���";
        return str;
}

int check_damage(object me, object target, int time);
int generate_msg(object me);

int cast(object me, object target)
{
        int time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ̫��ͼ��\n");
/*
        if(!me->query("taijitu_known"))
                return notify_fail("�㻹ûѧ��ʹ��̫��ͼ������\n");
*/              
        if((int)me->query_skill("spells") < 100)
                return notify_fail("�㻹������������̫��ͼ��\n");
        if( me->query_temp("cast_taiji"))
                return notify_fail("���Ѿ���ʹ��̫��ͼ��\n");        
        if((int)me->query("mana") < 1000 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("���޷����о�����\n");
/*
        if((int)me->query("faith") < 500 )
                return notify_fail("������һ������أ�\n");

*/      
        me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 200);
        if( random(me->query("max_mana")) < 500 ) 
        {
                write("��ʧ���ˣ�\n");
                return 1;
        }
        me->set_temp("cast_taiji",1);
        message_vision(HIR "\n$N�������˾����ģ����һ����߾����������̫�����Ρ�������\n���н��ƶ���Ѹ��������������$N��������ȥ,��Χ��ʱɱ���ķ���\n"
        NOR,me,target);
        me->set("env/invisibility", 1);
        time=me->query_skill("spells",1)/5 ;
        if(time>60) time=60;
        check_damage(me, target, time);
        me->start_busy(2);
        return 10+random(5);

}

int check_damage(object me, object target, int time)
{
        int ap,dp,damage,success;

        if( !target
        || !me 
        || environment(me) != environment(target)) 
        {
                remove_call_out("check_damage");
                me->delete_temp("cast_taiji");
                me->set("env/invisibility", 0);
                return 1;
        }

        ap= (int)me->query_skill("spells");
        ap= ap*ap*ap/10;
        ap= ap+(int)me->query("daoxing");

        dp= (int)target->query_skill("spells");
        dp= dp*dp*dp/10;
        dp= dp+(int)target->query("daoxing");
        damage=(int)me->query("max_mana")/10 - random((int)target->query("max_mana")/10);
        success=1;
        if( damage < 0 ) success = 0;
        if( random(ap+dp) < dp ) success = 0;
        if( (int)me->query("mana") < 30 ) success = 0;
        if( (int)me->query("kee")  < 30 ) success = 0;
        if( environment(me)->query("no_fight")
        || environment(me)->query("no_magic") ) success = 0;

        if( success )
        {
                if(random(2))
                {
                        message_vision(HIC"\n�Ʋ���������������ֵĹ�����ɽ�������󴸳�$n������\n"NOR,me,target);
                        message_vision(HIR"\n$n���ɽ��Ĵ��ҵ����ΰ��أ����ˤ���ڵأ�\n"NOR, me, target);
                        target->receive_damage("kee", random(damage)*2, me, "cast");
                        target->receive_wound("kee", damage/2, me, "cast");
                        COMBAT_D->report_status(target);
                        me->receive_damage("sen", 25);
                        me->add("mana", -25);
                        //if(!me->is_busy()) me->start_busy(2); 
                } 
                else 
                {
                        message_vision(HIC"\n�׹���ĸ˫˫��������ʱ���ɳ��ʯ��\n"NOR, me, target);
                        message_vision(HIR"\n$n���������ò��վ�����ȣ����ǲ����ˣ�\n"NOR, me, target);
                        target->receive_damage("sen", random(damage)*2, me, "cast");
                        target->receive_wound("sen", damage/2, me, "cast");
                        COMBAT_D->report_sen_status(target);
                        me->receive_damage("sen", 25);
                        me->add("mana", -25);
                        //if(!me->is_busy()) me->start_busy(2);      
                }
        }
        time--;
        if( time ) 
        {
                call_out("generate_msg", 4, me);
                call_out("check_damage", 8, me, target, time);
        }
        else 
        {
                me->delete_temp("cast_taiji");
                me->set("env/invisibility", 0);
                return 1;
        }
        if( !target->is_fighting(me) ) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
        return 1;
}

int generate_msg(object me)
{
        string *msgs=({
                HIR"\n������Ӱ���أ������ɽ�����������\n"NOR,
                HIY"\n�����Ʈ���Ŵ��죬������ա���\n"NOR,
                HIB"\n��ػ����У����������Ĵ�������\n"NOR,
                MAG"\n��Χ������Ӱ�����Ѿ�����������򡭡�\n"NOR,
        });
        if( !me ) return 1;
        tell_room( environment(me), msgs[random(sizeof(msgs))]);
        return 1;
}

