// ����������
// ר���鶾����ô�ã�ʲôʱ�����Ҳ��⣬�Ǻ�
// xintai 2/3/2001

#include <ansi.h>

int cast(object me, object target)
{

        if ( !target
          || !userp(target)
          || target->is_corpse()
          || target==me)
                return notify_fail("������˭����鶾��\n");
        if (!target->query_condition("xiangsi"))
        return notify_fail("�Ǹ��˸���û���鶾����ʲô��Ц����\n");
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("ս�����޷��ⶾ��\n");

        if( (int)me->query("mana")  <  1200 )
                return notify_fail("��ķ���������\n");

        if ( (int)me->query_skill("pansi-dafa") < 120)
                return notify_fail("�����˿�󷨵ȼ���������Ҫ��ǿ����\n");
        
        message_vision(
                 );
       
                target->apply_condition("xiangsi",0);
                
        me->add("mana", -300);
        return 1;
}
