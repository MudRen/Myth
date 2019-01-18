//Cracked by Roath
// perform.c
#include <ansi.h>
#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object weapon, target;
	string martial, skill, perf;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

        if (me->is_perform())
                return notify_fail("������ʹ��"+me->query_perform()+"��\n"); 

        // mudring Dec/03/2002
        if (me->query_temp("no_pfm") > time())
                return notify_fail("( ����Ϣ���ȣ�����ʩ���⹦��)\n");

	if( !arg ) return notify_fail("��Ҫ���⹦��ʲô��\n");
	if ( !wizardp(me) && environment(me)->query("no_fight")) 
		return notify_fail("���ﲻ��ʩ���⹦��\n");

        if( sscanf(arg, "%s on %s", perf, arg)==2 ) {
                target = present(arg, environment(me));
                if( !target ) target = present(arg, me);
                if( !target ) return notify_fail("����û�� " + arg + "��\n");

                if(!valid_kill(me,target,0)) return 0;
                set_to_killer(me,target);
                
//        if( userp(target) && (int)me->query("nopk") || (int)target->query("nopk"))
//        	return notify_fail(HIG"�Ѿ��ܵ�����������ɱ�ˣ�\n"NOR);	

        if(me->query("combat_exp")<250000 && userp(target))
                return notify_fail("�Լ�����û���þ���ɱ�ˣ�\n");
    if (userp(me) && environment(me)->query("short")!="������" )
       {
        if(me->query("daoxing")<200000 && userp(target))
                return notify_fail("�Լ�����û���þ���ɱ�ˣ�\n");  
        if(userp(target) && target->query("age")<17)
                return notify_fail("��վ��ʱ�������֡�\n");
            }
                if( userp(me) && userp(target) && 
                    target->query_temp("netdead") )
                   return notify_fail("�Է����ڶ����У����ܶ���ʩ���⹦��\n");

                arg=perf+" "+arg;
        } else if(sscanf(arg, "%s %s", perf, arg)==2 ) {
	  //so can't use: perform vision id
	  //but have to use: perform vision on id
	  arg=perf;
        }

	if( weapon = me->query_temp("weapon") )
            martial = weapon->query("skill_type");
        else
            martial = "unarmed";

//	write(martial+" "+me->query_skill_mapped(martial)+"\n");

	if( stringp(skill = me->query_skill_mapped(martial)) ) {
//	write(arg+" "+SKILL_D(skill)->perform_action(me, arg)+
//		SKILL_D(martial)->perform_action(me, arg)+"\n");
		notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
		if( SKILL_D(skill)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			return 1;
		} else if( SKILL_D(martial)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(martial, 1) )
				me->improve_skill(martial, 1, 1);
			return 1;
		}
		return 0;
	}

	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��


���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}
