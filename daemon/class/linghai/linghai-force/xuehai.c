//linghai-force
//Ѫɱ

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
        int lh;
        int lhh;
        int tg;

        if( !me->is_fighting() )
                return notify_fail("ֻ����ս���жԵ���ʹ�ã�\n");

        if(!target)target = offensive_target(me);
        if(target==me) target = offensive_target(me);

        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
  
        lh = me->query_skill("linghai-force",1);

        if( lh < 120 )
                return notify_fail("��ġ��躣�ķ�����򲻹���ʹ������Ѫ���ޱߡ�!\n");

        lhh = me->query_skill("force")+me->query_skill("spells");
        message_vision(HIR+"$N�ٺ�һЦ���������$n����һ�ơ�\n\n"HIR"$N��$n������ӣ�����ͷ��������������֪����ʲô���..\n"+NOR,me,target);

        if(random((me->query("combat_exp")))>(int)target->query("combat_exp")/3 )
{
     message_vision(
                HIB +
"$N"HIB"ֻ�����ؿ�һ����ʹ��æ�ջ�˫�ƣ���ʹȴԽ��Խ������\n"+NOR,target,me);
        target->receive_damage("kee",target->query_skill("force")/2+110,me,"pfm");
        target->receive_wound("kee",lhh,me,"pfm");
        target->start_busy(3+random(4));
      me->add("force",-200);
      me->add("sen",-80);
}
else
{
         message_vision(
                HIY +
"$n����������񣬺����������ӹ��˽١�\n"+NOR,me,target);
}
        me->add("force", -400);
        me->start_busy(1+random(2));

        return 1;
}


