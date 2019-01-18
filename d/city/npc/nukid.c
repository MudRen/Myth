/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// NPC /d/city/npc/nukid.c
// Created by waiwai@2000/07/09

#include <allnpc.h>
void reveal(object who);

void create()
{
       set_name(HIM "小女孩" NOR, ({"kid"}));
       set("gender", "女性");
       set("combat_exp", 100);
   	set("per", 19);
   	set("str", 10);
       set("age", 8);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("chat_chance", 20);
        set("chat_msg", ({
            CYN"小女孩对你说:我找不到我那只小猫咪了。\n"NOR,
            (: random_move :)
        }) );

	set("zombie",1);
	setup();
	carry_object(CITY_OBJ"kid-cloth")->wear();
//            carry_object(DOBJ"book/baguatu");
}

void init()
{
       object ob;

	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
        if (objectp(present("catty", environment(ob)))) {
		command("lead catty");
		command("kiss catty");
		say("小女孩说道：可找到你这个小东西了，别跑。。。。\n"NOR);
	}
       }
}

int accept_object(object me, object ob)
{
	object book;

	if( me->query("zy/hj")>0){
       if((string)ob->query("name") == "天杀星的头颅") {
		command("wa " + me->query("id"));
              me->add("potential", 10000); 
              me->add("combat_exp", 50000); 
              me->delete("zy/hj");
                    message_vision(HIY""+me->name()+"得到了50000点武学和5000点潜能！！！\n"NOR, me); 
     message("system",HIR"〖"HIG"门派浩劫"HIR" 〗"HIW"据说 "HIY+me->query("name")+HIW" 砍下了天杀星的头颅，换到了丰厚报酬！！！\n"NOR,users());    
       		return 1;
        }
        } else {
            command("say 嘻嘻．．．加油呀。");
            return 1;
        }
}

void relay_channel(object ob, string channel, string msg) 
{
        string who;
        if( !userp(ob) || (channel != "rumor") ) return;
//      if (wizardp(ob)) return;
        who = ob->query("name");
        if( ob==this_object() ) return;
        message_vision(who+" says:"+msg+"\n");
        if (!random(4)) {
          remove_call_out("reveal");
          call_out("reveal",1,ob);
        }
}

void reveal(object who) 
{
  string name=who->query("name"),id=who->query("id");
  switch (random(3)) {
 //  case 0: command("rumor* 某人恶狠狠地威胁道："+name+"，你个"+RANK_D->query_rude(who)+"！给我闭嘴！");break;
 //   case 1: command("rumor* 某人向"+name+"摇摇食指，「小朋友，这样不可以喔！」");break;  
     case 0: command("say "+name+"这"+RANK_D->query_rude(who)+"又在造谣了。");break;
     case 1: command("say "+name+"怎么那么喜欢造谣呀。");break;
     case 2: command("rumor* 某人客客气气地对"+name+"道：是不是你在造谣？如果是的话请你别再折腾了。");break;
  }
}

void unconcious() { die (); }
