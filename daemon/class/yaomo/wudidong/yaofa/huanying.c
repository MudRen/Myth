// ����������Ӱ

#include <ansi.h>
#include <command.h>

inherit SSERVER;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);

int cast(object me, object target)
{
	object env, obj;
	int mymana=me->query("mana"), cost=100, i, n;
	int success, ap, dp;
	string msg;
	string *dirs, target_dir, dest;
	mapping exit;

	seteuid(getuid());

	if( !target ) target = offensive_target(me);

	if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���������\n");

	if( !me->is_fighting(target))
		return notify_fail(target->query("name")+"��û������ս������Ҫ�û�Ӱ��������\n");

	if(target->query_temp("no_move"))
		return notify_fail(target->query("name")+"�Ѿ����������ˣ�\n");

	if(me->is_busy())
		return notify_fail("����æ���أ������������ɣ�\n");

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("yaofa", 1) < 50)
		return notify_fail("�㻹ûѧ���Ӱ����\n");

        if( mymana < cost )
                return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
                return notify_fail("��ľ���û�а취��Ч���У�\n");

	env = environment(me);
	exit = env->query("exits");

	if( !mapp(exit)) 
		return notify_fail("���뽫"+target->query("name")+"�����Ƕ�ȥ��\n");

	dirs = keys(exit);
	n = sizeof(exit);
	i = random(n);
	dest = exit[dirs[i]];

	if( !undefinedp(default_dirs[dirs[i]]) )
                target_dir = default_dirs[dirs[i]];
        else
                target_dir = dirs[i];

	if(!(obj = load_object(dest)) )
		return notify_fail("�޷��ߣ�\n");

	me->add("mana", -cost);
	me->receive_damage("sen", 10);

	msg = HIC "$N�������˾����ģ��ſ����һ�����̡�\n" NOR;
	msg += HIC "������ֻ��һ����Ӱ��" + target_dir + "��ȥ��\n" NOR;

	success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;

	// mon 1/21/99
	message_vision(msg, me, target);
	if(success==1 && !GO_CMD->main(target, dirs[i], 0)) {
	    success=0; // failed to go.
	}

	if(success == 1) {
		msg = HIR +target->name()+
		    "��" + target_dir + "׷ȥ��\n" NOR;
	}
	else {
		msg = HIR "$n��Ϊ��������Ӱ��ʧ���ˡ�\n" NOR;
	}

	message_vision(msg, me, target);

	if(success == 1) {
		msg = HIR "ֻ��"+target->name()+
		    "���˽������Ĵ�������ȴʲô��û���֡�\n" NOR;
               	message( "vision", msg, environment(target), ({target}));
		tell_object(target,
			"�㼱��ææ���˹������Ĵ�������ȴʲô��û���֡�\n");
               	return 5;
	} else {
		me->start_busy(1+random(2));
		return 3;
	}
}


