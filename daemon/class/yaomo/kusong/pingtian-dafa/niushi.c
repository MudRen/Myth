// niushi.c

inherit SSERVER;

string get_name(string str)
{
        str="�ٻ�ţʭ";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"����ٻ����ţʭΪ���æ��";
        return str;
}

int cast(object me, object target)
{
        int invocation_time,k,i;
        object soldier;
        
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ�ţʭ��\n");
                
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        
        if((time()-me->query("last_invocation"))<invocation_time)
                return notify_fail("������������׳��ʭ���Ѿ����������ˣ�\n");
            
        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ��������ˣ�\n");
                
        if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����޷����У�\n");
                
        message_vision("$N�����ҡͷ��һ�������˼��¡�\n\n", me);
        me->add("mana", -80);
        me->receive_damage("sen", 100);
        if( random(me->query("max_mana")) < 50 ) 
        {
                message("vision", "����ʲôҲû�з�����\n", environment(me));
                return 1;
        }
        k=(int)me->query_skill("pingtian-dafa")/20;
        if (k>5) k=5;
        for (i=1;i<=k;i++)
        {
                seteuid(getuid());
                soldier = new("/obj/npc/niushi");
                soldier->move(environment(me));
                soldier->invocation(me);
                soldier->set_temp("invoker",me);
        }
        me->set("last_invocation",time());
        me->start_busy(2+random(2));
        return 8+random(5);
}

