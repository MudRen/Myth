void check2()
{
       object ob,me,*inv;
       int i,level;
        ob=this_object();
        me=query("owner");
          if(me->query("combat_exp") <10000000 ) return ;
        if( ! living(me) && is_fighting(me) ) return ;
     level=random(3)+1;
        if(!me->query("rulaitask") ) return ;
        if(me->query("kee")<10 && me->query("sen")<10 ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check2");
     return;
     }

     if(random(100)>90) command("bian "+me->query("id"));
     switch(random(6))
     {
        case 0:
        {
        message_vision(YEL"$N���һ�����䣬��ħ��Ѫ������һ��Ѫ����$n������\n",ob,me);


       if(random(4)==0)
                {
              message_vision(HIM"$N��Ѫ����������,�ܵ������˺���\n"NOR,me);
              me->receive_damage("kee",query("max_kee")/55);
              me->receive_wound("kee",query("max_sen")/55);
              me->receive_damage("sen",query("max_kee")/55);
              me->receive_wound("sen",query("max_sen")/55);
                }
        else
        message_vision(YEL"$N��æ����һ������ʱ������Ѫ����\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�����л��䣬��ʱ��ֻħ�����ſ������$n������\n",ob,me);

                if(random(4)==0)

                {
              message_vision(HIR"$N�����ֽŽű�ħ���������ˣ��ܵ�����ֲ����˺���\n"NOR,me);
              me->receive_damage("kee",level*query("max_kee")/25);
              me->receive_wound("kee",level*query("max_sen")/55);
              me->receive_damage("sen",level*query("max_kee")/25);
              me->receive_wound("sen",level*query("max_sen")/25);
                }
                else
                  message_vision(YEL"$N��������ǰһ�ӣ���ʱ���������ѣ�\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N����ͻȻ����һ��Ѫ��ɫ�Ļ��򣬻���������$n�ɹ�ȥ��\n",ob,me);

                if(random(4)==3)
                {
              message_vision(HIR"$N���Լ�ʱ��ܣ�����������Ļ��������ţ�\n"NOR,me);
              me->receive_damage("kee",2*query("max_kee")/55);
              me->receive_wound("kee",2*query("max_sen")/55);
              me->receive_damage("sen",2*query("max_kee")/55);
              me->receive_wound("sen",2*query("max_sen")/55);
                      if(random(40)>36)
                      {
                       inv = all_inventory(me);
                       for(i=0; i<sizeof(inv); i++) 
                        {
                        if(random(4)==1 && inv[i]->query("id") !="saiya zhanyi")
                           {
                         message_vision(HIW"$n��������Ϊ���̣�\n"NOR,me,inv[i]);
                          destruct(inv[i]);
                           }
                        }
                      }
                }
             else                 
              message_vision(HIR"$N��ʱ��ָһ�����÷�����$n�Ļ��򲦿��ˣ�\n"NOR,me,ob);
         }
        break;
         

  }
        if( random(10) == 5 && ob->query("eff_kee")<ob->query("max_kee"))
        {
           set("eff_kee", query("max_kee"));
           set("eff_sen", query("max_sen"));
           set("kee", query("max_kee"));
           set("sen", query("max_sen"));
           set("force", query("max_force"));
           set("mana", query("max_mana"));
        }

        remove_call_out("check2");

}
                                                                                                           
