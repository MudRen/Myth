

string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 300 )
        return ("�������ʹ�ݡ�");
    if ( me->query("combat_exp") < 100000 )
        return ("����ô�ܷ�����ȥ�أ�");
    if ( me->query("bad") == 0 )
        return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
      int i;
      string bname = who->name()+"��"+who->query("bad/name") + "��ͷ­";
     
     if ( (string)ob->query("name") != bname )
        return notify_fail("Ѧ�ʹ�ŭ�����㾹�Һ�Ū�ң�\n");
        
     if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("Ѧ�ʹ��ŭ��������ɱ��Ҳ������,С���ұ��㣡\n");
                i =who->query("combat_exp");
      who->add("office_number", 1);
      if (i< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
      else { 
      who->add("combat_exp", 1501);
 }
      who->add("potential", 50 + random(100) );
      command("smile");
      command("touch " + who->query("id"));
      tell_object(who,"Ѧ�ʹ���ͷ������Ӧ�ý�����\n");
//    message("channel:chat",HIY+"�������쳯��Ѧ�ʹ�(Xue rengui)��"+who->query("name")+"ɱ����"+who->query("bad/name")+"������һ�ȡ�\n"+NOR,users());
      who->delete("bad");
      return 1;
}

int done_bad()
{
        object who = this_player();
        if ( who->query("bad") == 0 )
        {
                tell_object(who,"������û���ӷ�Ҫɱ����\n");
                return 1;
        }
        command("qi");
        command("kick" + who->query("id"));
        tell_object(who,"Ѧ�ʹ�����ӿ����������ģ������ˣ���û�á�\n");
        who->delete("bad");
        return 1;
}
        

int do_job()
{      
        object me;
        me = this_player(); 
        
    if( me->query("job/sxy-done")>0)
    {
                tell_object(me,"������Ȱ��ϴε����񱨸����Ժ������Ҫ����\n");
                return 1;
    } 
    else 
    if( me->query("job/sxy")>0)
    {
                tell_object(me,"���������Ҫ�������ˣ���ȥ�سǡ�\n");
                return 1;
    } 
    else 
    if( me->query("combat_exp")<500000)
    {
                tell_object(me,"��Ϊ��͢Ч��֮�Ŀɱ������سǲ��Ƕ�Ϸ����Ҫ����������\n");
                return 1;
    }

    message_vision(CYN"Ѧ�ʹ��$N˵���������ȥ�ɣ�Ϊ��͢Ч�����������ٽݾ��ߡ�\n"NOR,me); 
        me->set("job/sxy", 1);
        me->apply_condition("sxy-job", 8);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        int gong,exp,pot,money;
        me = this_player();
        gong = me->query("job/gong");
        exp = gong * 250;
        pot = gong * 100;
        
    if( me->query("job/sxy-done")< 1)
    {
                tell_object(me,"�������û����ء�\n");
                return 1;
    }

    message_vision(CYN"Ѧ�˹��$N˵�������ò���Ϊ��������Ӧ��ˡ�\n"NOR,me);
    message_vision(CYN"Ѧ�ʹ��$N˵�������ܹ�����" + gong + "������\n"NOR,me);     
    message_vision(CYN"Ѧ�ʹ��$N˵�����ý�����" + exp + "�㾭�飬" + pot + "��Ǳ�ܣ�"+gong + "���ֵ��\n"NOR,me);        
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->add("office_number",gong); //Cigar ��2002.05.14����ȥ��silver����������ƽ����pot&exp���ӷ���֮��
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    return 1;
}
