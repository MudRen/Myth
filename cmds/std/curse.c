//Cracked by Roath
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string curse, spl, trg;
	object target;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" ����һ��������û����ɣ������½�ͷ��\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("���ﲻ׼�½�ͷ��\n");

	if( !arg ) return notify_fail("ָ���ʽ��curse <��ͷ> [on <Ŀ��>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
                if(!objectp(target)) 
	 		return notify_fail(" ��Ľ�ͷҪ����˭���ϣ�\n");
//        if( userp(target) &&
//                (int) target->query("combat_exp") < LOWER_LIMIT &&
//                !me->query("licensed_to_kill")
//          )
//                return notify_fail("������ɲ����Ըĵ���ǿ�����Ķ�ϰ��\n");
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("����û�� " + trg + "��\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");
	if( stringp(curse= me->query_skill_mapped("cursism")) )
		return (int)SKILL_D(curse)->curse_curses(me, spl, target);
		
	return notify_fail("�������� enable curseָ��ѡ����Ҫʹ�õĽ�ͷ����ϵ��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��curse <��ͷ> [on <Ŀ��>]
 
HELP
        );
        return 1;
}
