// modify by mudring

int do_task1()
{
    object me = this_player();
    object guai,xie;
    string where,msg;
    int level;

    if (me->query("combat_exp") < 1800000)
    {
        tell_object(me,"�����ѧ��Ϊ������������������\n");
        return 1;
    }

    if (me->query_condition("dajiu_job"))
    {
        write(CYN"������˵�������ɵ��Ŵ���أ������̡�\n"NOR);
        return 1;
    }

    if (me->query_condition("dajiu_job_busy"))
    {
        write("����������ͨ�쾵һ����������λ�����Ӷ���ƽ�����㻹�ǵȵ�������\n");
        return 1;
    }

    me->command("say �����������Ϊ�����ɣ�");

    guai = new(__DIR__"baohunpc");
    guai->bhnpc_copy(me);

    write(CYN"������˵����������" + guai->query("name") + "��" 
        + guai->query("place")+"����������°ȥ��"
        "�Ѿ��첻���ˣ���ȥ������ɡ�\n"NOR);

// 37      this_object()->command("job " + me->name() + "�ӵ�һ�����" + guai->name() + "������");

    me->delete_temp("baohu");
    me->set_temp("baohu/get",1);
    me->set_temp("baohu/guai", guai);
    me->set_temp("baohu/where", guai->query("where"));
    me->set_temp("baohu/id", guai->query("id"));
    me->set_temp("baohu/name", guai->query("name"));
    me->delete_temp("baohu/kk");

    me->apply_condition("dajiu_job", 35); // 5 min
    me->apply_condition("dajiu_job_busy", 35 + random(10)); // 5 min

    xie = new(__DIR__"shoes.c");
    xie->move(me);

    write("�������ͳ�һ˫ˮ��Ь�����㡣\n");
    me->start_busy(1);
    if (me->query("id") == "mudring") me->move(guai->query("where"));
    return 1;
}

int do_cancel1()
{
    object me;
    object guai;
    int tt;

    me = this_player();

    if (!me->query_condition("dajiu_job"))
    {
        tell_object(me,"��û����������\n");
        return 1;
    }

    me->command("say ���������ӿ�������Ϊ����ȡ�");
    me->add_busy(1);
    message_vision(CYN"\n������˵�����ðɣ������������ɴ�Ȱɡ�\n"NOR,me);
    if  (guai = me->query_temp("baohu/guai"))
         guai->leave();

    me->delete_temp("baohu");
    me->clear_condition("dajiu_job");
    me->apply_condition("dajiu_job_busy", 10 + random(5)); // added 60-90 sec
    me->add_busy(1);
    return 1;
}
