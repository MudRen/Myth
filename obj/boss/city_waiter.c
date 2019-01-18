//By Aeddy 2004-1-6
//xiaoer.c
#include <ansi.h>
inherit F_VENDOR_SALE;
string season  = NATURE_D->check_season();
string seasonF  = NATURE_D->check_seasonF();
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
                "tu": "/d/city/obj/tasktu",
           "lei lingzhu": "/d/obj/baowu/leizhu.c",
                "jiudai": "/d/moon/obj/jiudai",
           "deng":"/d/wizz/liwu/obj/deng2",
                "gourou": "/d/ourhome/obj/gourou",
                "pillow": "/d/obj/misc/pillow",
              //  "mao": "/d/lingtai/obj/shengmao",
                "cloth": "/d/obj/armor/gold-chanyi",
                "fire": "/obj/fire",
                "jitui": "/d/ourhome/obj/jitui",
                "ball":"/d/obj/misc/crystalball",
                "jinpai" : "/d/city/obj/jinpai" ,
                "candle":"/d/city/npc/obj/candle",
                "huasheng": "/d/ourhome/obj/huasheng",
                "zhinan": "/d/obj/misc/xiaqi-zhinan",
                "saozhou": "/d/quest/small/saozhou",
                "brush": "/d/quest/small/brush",
                "shoeshine": "/d/quest/small/shoeshine",
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

//Added by Aeddy@2004-1-6
//һ���и���ʱ�����ʻ��仯
void greeting(object ob)
{
       string time, respect;
	string banghui;
	object lp;

       if( !ob || !visible(ob) || environment(ob) != environment() ) return;

       if( ob->query("env/invisibility") ) return;

	time = NATURE_D->outdoor_room_event(); // ����
	respect=RANK_D->query_respect(ob); 

	banghui=(string)ob->query("banghui");
//	lp=new("/obj/lingpai");
//	lp->create(banghui);
//	destruct(lp);

       if(!banghui || query("banghui")!=banghui) { //��ͬ�����˵ķ�����Ϣ
              switch(time) {  // ʹ��switch �жϵ�ǰʱ��                         
                      case "event_sunrise": // ����
                              message_vision(WHT"$NЦ�Ŷ�$n˵��������λ" + respect 
                      + "����������簡����ӭ���١���\n", this_object(),ob);  
                              break; 
 
                      case "event_noon":   // ����
                              message_vision(WHT"$N�ܹ�����$n˵��������λ" + respect 
                      + "���ù��緹���𣿿���������\n", this_object(),ob);  
                              break; 

                     case "event_evening": // ����
                              message_vision(WHT"$NЦ�����ض�$n˵��������λ" + respect 
                      + "�������ˣ�������С��ЪЪ�ɣ������ư������۵ġ���\n", this_object(),ob);  
                             break; 

                     case "event_night": // ��ҹ
                             message_vision(WHT"$N��$n˵��������λ" + respect 
                     + "���ù������𣿿�����ȱ���Ъ��ɡ���\n", this_object(),ob); 
                             break; 

                     case "event_midnight": // ��ҹ
                             message_vision(WHT"$N����������۾��ض�$n˵��������λ" + respect 
                     + "����ô���ˣ�������ЪϢ������\n", this_object(),ob); 
                             break; 

                     default : // ȱʡ����Ϣ
                             message_vision(WHT"$NЦ����ض�$n˵��������λ" + respect 
                     + "�������ȱ����ɡ���\n", this_object(),ob); 
			     break;
             }
		return;
	} else 
//		if((string)lp->query("bangzhu_id")==ob->query("id")) {//�԰����������ʺ���Ϣ
//		command("say ԭ����"+log_id(ob)+"�������ٺ��꣬���Ϸ�ЪϢ��Σ�С���ź��ţ�\n");
//		command("bow "+ob->query("id"));
//		destruct(lp);
//		return;
//		}
//	else
	command("say ��λ"+RANK_D->query_respect(ob)+"�������������ɺã�\n");//��һ����ڵ��ʺ���Ϣ
//	destruct(lp);
	return;
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

