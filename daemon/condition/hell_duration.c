// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	
	if( duration == 35) {
	        object guard;
		seteuid(getuid());
        	guard = new ("/d/death/npc/guard/killer1");

		guard->move(environment(me));
		guard->set_leader(me);
		message_vision("\n\n����ǰ����һ�֣�$N��������˹�����\n", guard);
		message_vision("\n$N��$n���һ�������Һ����������ԣ����У�\n", guard, me);
		guard->kill_ob(me);
		me->fight_ob(guard);
	}
        if( duration == 20) {
                object guard;
                seteuid(getuid());
                guard = new ("/d/death/npc/guard/killer2");

                guard->move(environment(me));
                guard->set_leader(me);
                message_vision("\n\n����ǰ����һ�֣�$N��������˹�����\n", guard);
                message_vision("\n$N��$n���һ�������Һ����������ԣ����У�\n", guard, me);
                guard->kill_ob(me);
                me->fight_ob(guard);
        }
        if( duration == 2) {
                object guardb;
                seteuid(getuid());
                guardb = new ("/d/death/npc/guard/killer4");
                guardb->move(environment(me));
                guardb->set_leader(me);
                message_vision("\n\n����ǰ����һ�֣�$N��������˹�����\n", guardb);
                message_vision("\n$N��$n�ȵ�������ү������ץ�㣬�����߰ɣ�\n", guardb, me);
                guardb->kill_ob(me); 
                me->fight_ob(guardb);
        }

        if( duration == 2) {
                object guardw;
                seteuid(getuid());
                guardw = new ("/d/death/npc/guard/killer3");
                guardw->move(environment(me));
                guardw->set_leader(me);
		message_vision("\n\n����ǰ����һ�֣�$N��������˹�����\n", guardw);
                message_vision("\n$N��$n���һ�������Һ����������ԣ����У�\n", guardw, me);
                guardw->kill_ob(me); 
                me->fight_ob(guardw);
        }
	

	me->apply_condition("hell_duration", duration - 1);
	if( duration < 1 ) return 0;
	return 1;
}
