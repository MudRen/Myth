 // caipan.c  ��ֹpker������̨����pktime�Ĳ��� 
//  created by kuku 2002.8

inherit NPC;  

void create()
{
set_name("�����й�", ({"pan guan","cai pan"}));
       set("gender", "����");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);

  //      if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
}

void init()
{
        object me,ob;
        me=this_object();
        ob=this_player();
       
        ::init();

       
       if(ob->query_condition("no_pk_time")) 
          {
        message_vision("��ɱ�������ڼ䲻�������̨����!����$N��$nһ���߳�������ݡ�\n",me,ob);
             ob->move("/d/city/center");
                message_vision("$N����һ�����˹��������ˤ���ڵء�\n",ob);
                ob->start_busy(5);
          }      
                        
        else if( interactive(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
              
        
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                           + "�ǲ��������ѽ�����ͼ���!\n");
                        break;
        }
}


