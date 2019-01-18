// fenshen.c ������

inherit SSERVER;

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"����һ��Ϊ�����ü�������㹥���Է��Լ������Է��Ĺ�����";
        return str;
}

int cast(object me, object target)
{
        int fenshen_time; //this time is the time interval fenshen can be used again. 
        object soldier;

        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в���ʹ�÷�����\n");

        fenshen_time=60+(200-(int)me->query_skill("spells"));
        if(fenshen_time<60) fenshen_time=60;
        if((time()-me->query("last_fenshen"))<fenshen_time)
                return notify_fail("��ոշֹ����ٷ����Σ�գ�\n");
                //hehe...at least 1 minute between 2 fenshens to
                //prevent ppls using too many ���� to kill top masters...weiqi.
        
        if( (int)me->query("mana") <4*(int)me->query_skill("spells"))
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("��ľ����޷����У�\n");

        message_vision("$N�૵����˼������\n", me);

        if( random(me->query("max_mana")) < 200 ) {
                me->add("mana",-(int)me->query_skill("spells"));
                me->receive_damage("sen",10);
                message("vision", "����ʲôҲû�з�����\n", environment(me));
                return 1;
        }

        me->add("mana", -4*(int)me->query_skill("spells"));
        me->receive_damage("sen", 40);

        seteuid(getuid());
        soldier = new("/obj/npc/jiashen");

        soldier->move(environment(me));
        soldier->invocation(me);
        soldier->set_temp("invoker",me);
        me->set("last_fenshen",time());
        me->start_busy(2+random(2));

        return 3+random(5);
}

