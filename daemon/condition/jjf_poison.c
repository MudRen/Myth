int update_condition(object me, int duration)
{
                                                
        me->receive_wound("sen", 10);
        me->receive_wound("kee", 10);
        me->set_temp("death_msg","�����������ˡ�\n");
        me->apply_condition("jjf_poison", duration - 1);

        if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
                message_vision("$N���������ͣ���ƺ���ʱ���ᵹ��ȥ��\n", me);
        else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
                message_vision("$N��Ŀ���ף����в���������ĭ��\n", me);
        else 
                message_vision("$N��ɫ���ƣ���֫������ͣ��\n", me);

        if( duration < 1 ) return 0;
        return 1;
}

