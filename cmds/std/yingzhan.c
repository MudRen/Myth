#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  object env;
   object target;

  if( me->is_ghost() )
    return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");

  if( me->is_fighting() )
    return notify_fail("ս���в���Ӧս��\n");

  if (!me->query_temp("ask_yingzhan"))
    return notify_fail("��û��Ӧս������\n");

    message_vision("$N��ʧ��һ������֮�С�\n",me);
  me->move(me->query_temp("yingzhan_place"));
  message_vision("$N�����ڴ�ҵ���ǰ��\n",me);
  target=me->query_temp("yingzhan_man");
  message_vision("$N��$n���һ����"+RANK_D->query_rude(target)+"�ҵ����ǵĵ�ͷ�������ң�\n",me,target);
  me->kill_ob(target);
  target->kill_ob(me);
  me->delete_temp("yingzhan_man");
  me->delete_temp("no_move");
me->delete_temp("ask_yingzhan");
  me->delete_temp("yingzhan_place");
  me->set_temp("in_tiaozhan",1);
  return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : yingzhan

���ָ�����㵽ָ���ĵص�Ӧս��

HELP
    );
    return 1;
}


