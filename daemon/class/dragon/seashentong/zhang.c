#include <ansi.h>

inherit SSERVER;

void remove_zhang(object me);

int cast(object me, object target)
{
        int skill,addkee;

        if( target != me ) 
                return notify_fail("��ֻ�ܶ��Լ������������\n");

        if( (int)me->query("force") < 700 )     
                return notify_fail("�������������\n");
	if( (int)me->query("mana") < 700 )
		return notify_fail("��ķ������㡣\n");
	if( (int)me->query("max_force") < 500 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_mana") < 500 )
		return notify_fail("��ķ������㡣\n");	
	if( (int)me->query("sen") < 200 )
                return notify_fail("��ľ����޷����У�\n");	
        if( (int)me->query_temp("powerzhang") ) 
                return notify_fail("�����ڱ仯���ˡ�\n");
        if (me->is_busy() || me->query_temp("pending/exercising")
        	|| me->query_temp("doing_xiudao")|| me->query_temp("pending/meditating"))
              return notify_fail("��������æ���أ��Ȼ����˵�ɡ�\n");          

        skill = (me->query_skill("dragonforce",1)+me->query_skill("seashentong",1)+2)/2;
	if(skill<50)
        addkee= ((int)me->query("max_kee"))/5;
	else if(skill<100)
        addkee= (((int)me->query("max_kee"))*2)/5;
	else if(skill<200)
        addkee= (((int)me->query("max_kee"))*3)/5;
        else if(skill<300)
        addkee= 4*((int)me->query("max_kee"))/5;
	else
        addkee= (int)me->query("max_kee");
	
        me->set("kee", (int)me->query("max_kee"));
	me->add("kee", addkee);
        me->set("eff_kee", (int)me->query("max_kee"));
        me->add("eff_kee", addkee);
        me->receive_damage("sen", 100);
        me->add("force", -500);
        me->add("mana",  -500);
        
        message_vision(HIW"$N�������ʹ��������ص���ͨ������һ������������\n��ʱ��ɸ�������ɣ�����ʮΧ�ľ��ˡ�\n"NOR, me);

        me->set_temp("powerzhang", 1);
        me->start_busy(3);
   me->start_call_out( (: call_other, __FILE__, "remove_zhang", me :),skill*3/4);

        return 1;
}

void remove_zhang(object me)
{
        me->set("kee",(int)me->query("max_kee"));
        me->set("eff_kee",(int)me->query("max_kee"));
	me->delete_temp("powerzhang");
        message_vision(HIW"$N����������˷�����Ȼ������ԭ��\n"NOR, me);
	return;
}
