// Modified By Longer@SJSH

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg,start;
        int ap, dp, success;
        target = offensive_target(me);
        //always use the one who is fighting me as target.

        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("�㲻���¹����ӣ���λ���Ӱ��\n");
                
        if( me->is_busy())
                return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
                return notify_fail("�㾫��̫����Լ��о������䡣\n");

        if( (int)me->query_skill("moonshentong", 1) < 20)
                return notify_fail("��δ��ѧ����Ӱ��\n");

        if(environment(me)->query("under_water"))
                return notify_fail("����ˮ�У�û��ʩ����Ӱ��\n");

        ap=me->query_skill("spells")+me->query("max_mana")/10;
        if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

        if(!me->is_fighting() )
        {
                me->add("sen", -me->query("max_sen")/8);
                me->add("mana", -80);
                message_vision(HIB"�¹⵭���ĸ���һƬ���֣�\n��͵�������$N��\n�����֮���������衣\n����ɽˮ�䣬\n��������飬\n$N����Ӱ��翲������������¹��С�\n"NOR,me);
                success=1;
        }
        else
        {
                if(random(ap+dp)>dp/2)
                {
                        msg=HIB"�¹⵭���ĸ���һƬ���֣�\n��͵�������$N��\n�����֮���������衣\n����ɽˮ�䣬\n��������飬\n$N����Ӱ��翲������������¹��С�\n"NOR;
                        me->add("sen", -me->query("max_sen")/6);
                        me->add("mana", -50);
                        success=1;
                }
                else 
                msg = HIG"��$n���һ����������㣬�����ܣ��һ��л�˵�ء�����$N����������\n"NOR;
                me->add("mana", -50);
                message_vision(msg, me, target);
        }
        if(success)
        {
                start=me->query("env/destination");
                start=me->query("�Ǻ�/"+start);
                if(!start || !find_object(start))
                        start=me->query("startroom");
                if(!start) start="/d/city/kezhan";
                me->move(start);
                message("vision", HIG+me->name()+"Ʈ����������Ӱ����������ǰ��\n������Ľ�ĸо���\n�·�������ȴ������ĺ쳾��Ӱ��\n�����������翵����֮�У�\n��֪��ʱ��\n�쳤�ؾ��ƺ��ѱ�Ĳ԰�������\n����ʯ������ȴ�����ޡ�\n"NOR,
                                  environment(me), me);
                return 3+random(3);
                tell_object(me, HIM"һ��Ѥ������ʺ������������ǰ��\n������ȶ��˵���Ӱ�����ĸ��ֳ�����\n��ʱ�䵶�⽣Ӱ���������������͵��¹��У�\n����ô����ܰ����\n"NOR);
        }
        return 5+random(5);
}

