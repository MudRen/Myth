// by mudring

int do_task2()
{
    object me = this_player();
    object guai;
    string where;
    int tt;

    if (me->query("combat_exp") < 1800000)
    {
        tell_object(me,"�����ѧ��Ϊ������������������\n");
        return 1;
    }

    if (me->query_condition("baohu_job"))
    {
        write(CYN"��������ɫһ�����¹������������ж���\n"NOR);
        return 1;
    }

    if (me->query_condition("job_busy"))
    {
        write("����������ͨ�쾵һ��������ħ��û�в�ȡʲô�ж�������ల���¡�\n");
        return 1;
    }

    me->command("say �������ħ�����ң�");

    guai = NPC_D->task_npc();
    where = guai->query("place");
    me->delete_temp("dajiu");
    me->set_temp("dajiu/get", 1);
    me->set_temp("dajiu/id", guai->query("id"));
    me->set_temp("dajiu/name", guai->query("name"));
    me->set_temp("dajiu/where", where);
    me->delete_temp("dajiu/kk");
    me->apply_condition("baohu_job", 35); // 5 min
    me->apply_condition("job_busy", 35 + random(10)); // 5 min

    write(CYN"������˵����ҹ���������ħ���п��ܶ�" + guai->query("name") +
        "("+ guai->query("id") + ")����������ȥ" + where + "�����䰲ȫ��\n"NOR);
/*
    this_object()->command("job " + me->name() + 
        "�ӵ�һ������" + guai->name() + "������");
*/
    me->start_busy(1);
    if (me->query("id") == "mudring") me->move(guai->query("where"));

    return 1;
}

int do_cancel2()
{
    object me = this_player();

    if (!me->query_condition("baohu_job"))
    {
        tell_object(me,"��û����������\n");
        return 1;
    }

    me->command("say ���������ӿ�������Ϊ��������");
    message_vision(CYN"������˵�����ðɣ�������������ȥ������\n"NOR, me);
    me->delete_temp("dajiu");
    me->clear_condition("baohu_job");
    me->apply_condition("job_busy", 10 + random(5)); // added 60-90 sec
    me->start_busy(1);
}

