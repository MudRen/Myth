//xiaoer.c

inherit F_VENDOR_SALE;

void clear_room();

void create()
{
       reload("city_xiaoer");
       set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","��С��");
       set("gender", "����");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
// 22                    "cake": "/d/quest/liwu/cake",
                "tu": "/d/city/obj/tasktu",
           "lei lingzhu": "/d/obj/baowu/leizhu.c",
                "jiudai": "/d/moon/obj/jiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "pillow": "/d/obj/misc/pillow",
              //  "mao": "/d/lingtai/obj/shengmao",
                "cloth": "/d/wizz/junhyun/obj/gold-chanyi",
                "fire": "/obj/fire",
                "jitui": "/d/ourhome/obj/jitui",
                "ball":"/d/obj/misc/crystalball",
                "jinpai" : "/d/city/obj/jinpai" ,
                "candle":"/d/city/npc/obj/candle",
                "huasheng": "/d/ourhome/obj/huasheng",
                "zhinan": "/d/obj/misc/xiaqi-zhinan",
                "saozhou": "/d/quest/small/saozhou",
        ]) );

  //      if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
        remove_call_out("clear_room");
        call_out("clear_room",300);
}

void init()
{
        object me,ob;
        object *inv;
        int i;
        me=this_object();
        ob=this_player();
       
        ::init();

// added by mudring.
        inv = deep_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (
                    !playerp(inv[i])
                    )
                    continue;
                message_vision("���뷷���˿ڲ��ɣ���!����$Nһ�Ѱ�$n���˳�ȥ��\n",me,ob);
                ob->move("/d/city/zhuque-s1");
                message_vision("$N����һ�����˹��������ˤ���ڵء�\n",ob);
                ob->start_busy(5);
        }
       
        if (ob->query_condition("no_pk_time") || 
            ob->is_zombie() || 
            ob->query("name") == "���ִ���")
          {
                message_vision("��ɱ�������ڼ䲻Ҫ��Ӱ����������!����$Nһ�Ѱ�$n���˳�ȥ��\n",me,ob);
                ob->move("/d/city/zhuque-s1");
                message_vision("$N����һ�����˹��������ˤ���ڵء�\n",ob);
                ob->start_busy(5);
          }      
                        
        else if( interactive(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
              
        
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "������ЪЪ�ţ������Ѱɡ�\n");
//����˵ˮ½����������ô�����ϣ����ֿ��˹�ඣ���Ҫ��֪������ϸ�ģ������¥����������ʾ��
//Ҫ��Ȼ�㿴���Ա���λƯ����С����ô����������Ҳ�С�
                        break;
        }
}

void clear_room()
{
        string *place1 = 
        ({"/d/city/zhuque-s1","/d/city/center","/d/city/xuanwu-n1",
        "/d/city/baihu-w1","/d/city/qinglong-e1",});
        string room;
        int race, obj,i;
        object *inv;    
        race = 0;
        obj = 0;        
        if(environment(this_object())){
        inv = all_inventory(environment(this_object()));
        say(name()+"��Ǹ��˵������С����ɨ����λ�͹�ԭ���������\n");
        for (i = 0;i <sizeof(inv);i++)
        {
                if(inv[i]->query("race")=="Ұ��") 
                {
                        room = place1[random(5)];
                        say(inv[i]->query("name")+"��"+name()+"��ɨ����˳�ȥ��\n");
                        inv[i]->set_temp("no_return",0);
                        inv[i]->set_temp("rider",0);
                        inv[i]->move(room);
                        tell_room(environment(inv[i]), inv[i]->query("name")+"��"+name()+"�ӿ�ջ���˳�����\n");
                        race++;
                }
                else if(!inv[i]->is_character()&&!inv[i]->query("board_id"))
                 {obj++; 
                 destruct(inv[i]);}
                else if(inv[i]->query_temp("ridee"))
                {
                        inv[i]->set_temp("ridee",0);
                        inv[i]->add_temp("apply/dodge",-inv[i]->query_temp("ride/dodge"));
   
                 }
        }
     }
      remove_call_out("clear_room");
      call_out("clear_room",600);
}
int accept_object(object who, object ob)
{
    int value;

        if (ob->query("money_id") && (value=ob->value()) >= 300) 
        {
                tell_object(who, name()+
                        "һ������˵������л���ϣ��͹����Ϸ�ЪϢ��\n");
                who->set_temp("rent_paid",1);
                take_money(value, 300);
                return 1;
        }
        return 0;
}

