
string ask_tongchuan()
{
    object me, ob;
    string msg;
       
    ob = this_player();
    me = this_object();
      
    if (ob->query("family/name") != me->query("family/name"))
    return "�������ˣ��ι����ˣ�";
    if ((int)ob->query_condition("tongchuan_job"))
    {
        if (ob->query_temp("tongchuan/id"))
            return "��������ȥ����" + ob->query_temp("tongchuan/name")+"��������ô�������";
        else
            return "����ûʲô����Ҫ���أ���Ȼ�������ɡ�";
    }

    if (ob->query_condition("job_busy"))
        return "����ûʲô����Ҫ���أ���Ȼ�������ɡ�";

/*
    if (ob->query("combat_exp") >= 10000000)
        return "������ô���������Ǳ����ű��˺á�";
*/

    if (ob->query("combat_exp") < 12000)
        return "���ٲ�֪��ߵغ�ʲô���Ҵ���";

    message_vision("$N�ó�һ�����ͽ����$n��\n",me,ob);

    me = NPC_D->task_npc();
    ob->delete_temp("tongchuan");
    ob->set_temp("tongchuan/id", me->query("id"));
    ob->set_temp("tongchuan/name", me->query("name"));
    ob->set_temp("tongchuan/get", 1);
    ob->set_temp("tongchuan/where", me->query("where"));
    ob->apply_condition("job_busy", 30 + random(20));
    ob->apply_condition("tongchuan_job", 30);
       
    switch(random(3))
    {
        case 0: msg = "��͢���١�" + me->query("name") +
                      "���������ȥ��" + me->query("place") + "��ͨ����";
                break;
        case 1: msg = "��͢��Ҫ�º͡�" + me->query("name") +
                      "�������������ϵ���" + me->query("place") + "��ȥ����һ�¡�";
                break;
        case 2: msg = "����˼����ѡ�" + me->query("name") +
                  "�������æȥ�ӡ�" + me->query("place") + "�������ҹ����ɡ�";
                break;
    }  
// 52      this_object()->command("job ����" + ob->name() + "���ٴ���" + me->name() + "���");
    me = new(__DIR__"ling");
    me->set("owner", ob);
    me->move(ob);
    if (ob->query("id") == "mudring") ob->move(ob->query_temp("tongchuan/where"));
    return msg + "\n";
}
