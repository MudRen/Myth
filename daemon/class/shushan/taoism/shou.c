// /daemon/class/shushan/taoism/shou.c ����̽����
// writted bye jie 2001-1-5
// ���ɽ����������ķ���̽����

#include <ansi.h>

inherit SSERVER;
int cast(object me, object target)
{
        
        string msg;

        object thing,*inv;
        if( !target ) target = offensive_target(me);
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("�㲻����ɽ���ɣ������á�����̽���֡�?\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("������̽���֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

                
        if( (int)me->query_skill("spells",1)<60)
                return notify_fail("����ɷ���������Ϊ̫ǳ������ʹ�á�����̽���֡���\n");
        if( (int)me->query_skill("taoism",1)<60)
                return notify_fail("��Ļ���������Ϊ̫ǳ������ʹ�á�����̽���֡���\n");
        if( (int)me->query_skill("sevensteps",1)<60)
                return notify_fail("����Ṧ�������ݣ�����ʹ�á�����̽���֡���\n");
        if( (int)me->query("mana",1)<50)
                return notify_fail("�����ڷ���̫��������ʹ�á�����̽���֡���\n");
                        
        msg = HIM "$NͻȻ����һչ��ʹ��������̽���֡���$n������ȥ��\n"NOR;

        if(random(me->query_skill("spells"))>target->query_skill("dodge")/2)
        {
                me->start_busy(3);
                target->start_busy(random(3));
                
                me->add("mana",-random(20));
                inv=all_inventory(target);
                if(!sizeof(inv))        
                {
                        msg +=HIW"$n���Ͽտ���Ҳ��$NʲôҲû��̽������\n"NOR;
                }
                else    
                {
                        thing=inv[random(sizeof(inv))];
                        if (!thing->query("no_get"))
                        {
                                thing->move(me);
                                msg +=HIM"$N���ֿտգ���$n���ϵõ�"+thing->query("unit")+thing->query("name")+"��\n"NOR;
                        }
                        else       
                        {
                                msg +=HIM"$N���ֿտգ���$n����͵ȡ"+thing->query("name")+"ʧ���ˣ�\n"NOR;
                        }
                }
        } 
        else 
        {
                me->start_busy(1);
                msg += HIW"����$n������$N����ͼ������һ�����˿�ȥ��\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

