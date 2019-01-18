#include <ansi.h>

inherit SSERVER;

int success_move(object me);
int failure_move(object me, object target);
int random_go(object me, string* dirs);

int cast(object me, object target)
{
	int a,b,c;

	object where;
	where=environment(me);

        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ���������\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����޷����У�\n");

        message_vision(HIC"$N�૵����˼������\n"NOR, me);

	a=(int)me->query_skill("spells");
	a=a*a*a/10;
	if (target) {
		b=(int)target->query_skill("spells");
		b=b*b*b/10;
	}

	if (where->query("water")) {
		c=50+random(50);
	} else if (where->query("outdoors")) {
		c=20+random(20);
	} else {
		c=10+random(10);
	}

	if(me->is_fighting()) {
		if(random(a*c/10) > b) {
			success_move(me);
		} else {
			failure_move(me, target);
		}	
	} else {
		success_move(me);
	}
	me->add("mana", -50);
	me->receive_damage("sen", 50);

        return 1;
}

int success_move(object me)
{
	string* dirs;
	dirs=({"/d/sea/", "/d/qujing/bibotan/"});

	message_vision(HIC"\n$N�Ľ���ͻȻӿ��һ��ˮ����ˮ������$N��֮�����ˣ�\n"NOR, me);

	random_go(me, dirs);
	
	return 1;
}
int random_go(object me, string* dirs)
{
        int i,j,k;
        object newob;
        mixed* file;

        if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return 1;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }
    if( (newob=find_object(dirs[i]+file[j][0])) )   {
		if(!newob->query("water") ){
			random_go(me, dirs);
			return 1;
		}
                me->move( newob ); 
message_vision(HIC"\nͻȻһ��ˮ��ӿ��$N�������˳�����\n"NOR, me);
        }
        else  {
                seteuid(getuid(me));
                newob = load_object(dirs[i]+file[j][0]);
                if (newob)   // now this is not necessary, only for debug use
		{
			if( !newob->query("water")){
				random_go(me, dirs);
				return 1;
			}
                        me->move(newob);
message_vision(HIC"\nͻȻһ��ˮ��ӿ��$N�������˳�����\n"NOR, me);
	}
        else  {
                        tell_object(me, "Error.\n");
                }
	}

        return 1;
}


int failure_move(object me, object target)
{
	message_vision(HIR"$N�Ľ���ͻȻӿ��һ��ˮ����ȴ��$nʶ�ƣ�$Nû���ܵ���\n"NOR, me, target);
	me->start_busy(3+random(3));
	return 5+random(5);
}
