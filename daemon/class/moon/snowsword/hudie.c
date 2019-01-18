#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,add_dodge;
        string *mapped;
        mapping map;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail(HIW"��ֻ����ս����ʹ�á�\n"NOR);
        if ( me->query("sen")<200 )
                return notify_fail(RED"��Ԫ�񲻼�,ǿ���˹��Ầ���Լ�!\n"NOR);
        if ( me->query("force")<500 )
                return notify_fail(RED"������������ǿ���˹��Ầ���Լ�!\n"NOR);
        extra = me->query_skill("moondance",1); 
        if (extra < 30) return notify_fail(RED"������������軹�������죡\n"NOR); 
        if (me->query_skill("snowsword",1)<60) 
                return notify_fail("��ķ��ѩ�轣����������!\n");
        if (me->query_temp("hudie_busy")) return notify_fail("�ȵ�������ɡ�\n"); 

        if( me->query_skill("moondance",1)<100 && me->query_skill("snowsword",1)<100)
        {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);                
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))  
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������.\n"NOR,target);
                        target->start_busy(3);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������.\n"+NOR,me);
                        me->start_busy(2);
                }
        }
        if( (me->query_skill("snowsword",1)<300)&&(me->query_skill("snowsword",1)>100))
        {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2)))  
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������..\n"NOR,target);
                        target->start_busy(2+random(3));
                        return 1;
                       
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������..\n"+NOR,me);
                        me->start_busy(3);
                }
        }
        if( me->query_skill("snowsword",1)>300 )   
        {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")*7/10)))                
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������...\n"NOR,target);
                        target->receive_damage("sen", extra, me, "pfm");
                        if(!userp(target)) 
                        {
                                target->add("eff_sen", -extra*2);
                                target->receive_damage("sen", extra, me, "pfm");
                        }
                                target->start_busy(4);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������...\n"+NOR,me);
                        me->start_busy(2);
                }
        }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("hudie_busy",1);
        call_out("remove_effect",4+random(3),me);
        return 1;
}

void remove_effect(object me) 
{
        if (!me) return;
        me->delete_temp("hudie_busy");
}

