// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	mapping skill;
	int cost, my_skill;
	
    if(environment(me)->query("no_fight") || 
       environment(me)->query("no_magic") )
          return notify_fail("���ﲻ�Ƕ���ĵط���\n");
                     	
	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("��������æ���ء�\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("��Ҫ��ʲô��\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("���޷�����������ѧ���κζ�����\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧѧ����ʶ��(literate)�ɡ�\n");

	message("vision", me->name() + "��ר�ĵ��ж�" + ob->name()
		+ "��\n", environment(me), me);
  
        my_skill=me->query_skill(skill["name"],1);

	if ( (string)SKILL_D(skill["name"])->type()=="martial" )
	{
		if( my_skill*my_skill*my_skill/10>(int)me->query("combat_exp") || (int)me->query("combat_exp") < skill["exp_required"] )
		{ write("�����ѧ��Ϊ��û��������磬�����û�õġ�\n");
		return 1; }
	}
	else if ( (string)SKILL_D(skill["name"])->type()=="magic" )
	{
		if( my_skill*my_skill*my_skill/10>(int)me->query("daoxing") || (int)me->query("daoxing") < skill["dx_required"] )
		{ write("��ĵ��л�û��������磬�����û�õġ�\n");
		return 1; }
	}

	notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query_int())/20;

        if (cost < 5) cost = 5;

	if( (int)me->query("sen") < cost ) {
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}

	me->receive_damage("sen", cost);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);
	me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);
	write("���ж��й�" + to_chinese(skill["name"]) + "�ļ��ɣ��ƺ��е��ĵá�\n");
	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study|du <��Ʒ����>

���ָ��ʹ����Դ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: �㲻���Ǹ�����ä����

see also : learn
HELP
   );
   return 1;
}
