void init()
{
        ::init();
        add_action("do_kill","kill");
        add_action("do_kill","hit");    
        remove_call_out("leave");
        call_out("leave",10);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "ħ����ų����ˣ�Ѹ����ʧ�������С�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();
        
        if(!arg || present(arg,environment(me))!=me) return 0;
        if (me->query("ygjg")==who)
                  {
                  message_vision(CYN"$N���ͣ�$N���ͣ�\n"NOR,who);
                  return 1;
                  }
            else if (me->query("ygjg"))
             {
                  tell_object(who,CYN"�㻹�Ǹ�˾��ְ��ר�ĶԸ���ĵ��˰ɡ�\n"NOR);
                  return 1;
                  }
                   return 0;
} 


