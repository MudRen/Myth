#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg,start;
        int ap, dp, success;
        target = offensive_target(me);
        //always use the one who is fighting me as target.

        if( me->is_busy())
                return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
                return notify_fail("�㾫��̫����Լ��о������䡣\n");

        if( (int)me->query_skill("seashentong", 1) < 70)
                return notify_fail("��δ��ѧ��ˮ�ݡ�\n");

        ap=me->query_skill("spells")+me->query("max_mana")/10;
        if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

        if(!me->is_fighting() )
        {
                message_vision(HIC"\n\n$N�Ľ���ͻȻӿ��һ��ˮ����ˮ������$N��֮�����ˣ�\n\n"NOR,me);
                me->add("sen", -me->query("max_sen")/8);
                me->add("mana", -80);
                success=1;
        }
        else
        {
                msg=HIC"\n\n$N�Ľ���ͻȻӿ��һ��ˮ����ˮ������$N��֮�����ˣ�\n\n"NOR;
                if(random(ap+dp)>dp/2)
                {
                        msg+=HIC"\n\nֻ��$N����һ���� ����������ˮ������$N��Ӱ�Ѿ������ˡ�\n\n"NOR;
                        me->add("sen", -me->query("max_sen")/6);
                        me->add("mana", -50);
                        success=1;
                }
                else msg+=HIR"\n\n$N�Ľ���ͻȻӿ��һ��ˮ����ȴ��$nʶ�ƣ�$Nû���ܵ�����\n\n"NOR;
                me->add("mana", -50);
                message_vision(msg, me, target);
        }
        if(success)
        {
                start=me->query("env/destination");
                start=me->query("�Ǻ�/"+start);
                if(!start || !find_object(start))
                        start=me->query("startroom");
                if(!start) start="/d/sea/yujie2";
                me->move(start);
                message("vision", HIC+me->name()+"��һ����ˮ֮�����˳���������ʪ���ܵġ�\n\n"NOR,
                                  environment(me), me);
                tell_object(me, HIG"\n\n�������֮Ӱ������һ���������������ֳ�����\n\n"NOR);
                return 3+random(3);
        }
        return 5+random(5);
 }
