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
       if ( me->query("sen")<30 )
            return notify_fail(RED"��Ԫ�񲻼�,ǿ���˹��Ầ���Լ�!\n"NOR);
//        if (!PFM_D->valid_family(me, "��˿��"))
//                return notify_fail("��Ƕ���֮�ˣ������ô��У�\n");
       if ( me->query("force")<100 )
            return notify_fail(RED"������������ǿ���˹��Ầ���Լ�!\n"NOR);
          extra = me->query_skill("yueying-wubu",1);
       if (extra < 30) return notify_fail(RED"��ġ���Ӱ�貽�����������죡\n"NOR);
    if( me->query_skill("yueying-wubu",1) <= 100 )
           {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp"))
                  {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������.\n"NOR,target);
                        target->start_busy(3);
                  }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������.\n"+NOR,me);
                        me->start_busy(1+random(1));
                 }
           }
else if( (me->query_skill("yueying-wubu",1) <= 300) && (me->query_skill("yueying-wubu",1)>100))
           {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                  if(random((int)target->query("combat_exp")*2/3) < random((int)me->query("combat_exp")))
                        {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������..\n"NOR,target);
// modified by tree,2001-10-8
//                            {me->start_busy(random(3));return 1;}
//                        me->start_busy(3);
                        target->start_busy(4);
                         }
                else
                    {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������..\n"+NOR,me);
                        me->start_busy(1+random(1));
                    }
            }
else if( me->query_skill("yueying-wubu",1)>300 )   
            {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")*7/10) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������...\n"NOR,target);

                        target->start_busy(5);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������...\n"+NOR,me);
                        me->start_busy(1+random(1));
                }
            }
       me->receive_damage("sen", 50);
       me->add("force", -100);
        return 1;
}

