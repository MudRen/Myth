/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// NPC /d/city/npc/nukid.c
// Created by waiwai@2000/07/09

#include <allnpc.h>
void reveal(object who);

void create()
{
       set_name(HIM "СŮ��" NOR, ({"kid"}));
       set("gender", "Ů��");
       set("combat_exp", 100);
   	set("per", 19);
   	set("str", 10);
       set("age", 8);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("chat_chance", 20);
        set("chat_msg", ({
            CYN"СŮ������˵:���Ҳ�������ֻСè���ˡ�\n"NOR,
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
		say("СŮ��˵�������ҵ������С�����ˣ����ܡ�������\n"NOR);
	}
       }
}

int accept_object(object me, object ob)
{
	object book;

	if( me->query("zy/hj")>0){
       if((string)ob->query("name") == "��ɱ�ǵ�ͷ­") {
		command("wa " + me->query("id"));
              me->add("potential", 10000); 
              me->add("combat_exp", 50000); 
              me->delete("zy/hj");
                    message_vision(HIY""+me->name()+"�õ���50000����ѧ��5000��Ǳ�ܣ�����\n"NOR, me); 
     message("system",HIR"��"HIG"���ɺƽ�"HIR" ��"HIW"��˵ "HIY+me->query("name")+HIW" ��������ɱ�ǵ�ͷ­�������˷�񱨳꣡����\n"NOR,users());    
       		return 1;
        }
        } else {
            command("say ��������������ѽ��");
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
 //  case 0: command("rumor* ĳ�˶�ݺݵ���в����"+name+"�����"+RANK_D->query_rude(who)+"�����ұ��죡");break;
 //   case 1: command("rumor* ĳ����"+name+"ҡҡʳָ����С���ѣ�����������ร���");break;  
     case 0: command("say "+name+"��"+RANK_D->query_rude(who)+"������ҥ�ˡ�");break;
     case 1: command("say "+name+"��ô��ôϲ����ҥѽ��");break;
     case 2: command("rumor* ĳ�˿Ϳ������ض�"+name+"�����ǲ���������ҥ������ǵĻ�������������ˡ�");break;
  }
}

void unconcious() { die (); }
