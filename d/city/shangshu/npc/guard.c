/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Npc: /d/city/shangshu/npc/guard.c
//Creat by waiwai@2001/05/12
//Pay Npc ֮һ

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ŷ�", ({ "guard" }) );
        set("id", "guard");
        set("long","���鸮���ŷ���Ȼûʲô���Σ������������\n"
                "����İ����޲������Ϲ��Ͼ��ġ\n");

        set("attitude", "peaceful");
	 set("area_name","������");
	 set("money_need",2000);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 1000);

        set("chat_chance", 5);
                set("chat_msg", ({
                "�ŷ������̵�˵���ǡ�����[�ݷ�]������˵��𣿡���\n",
                "�ŷ��ٺٵ�Ц��Ц������Ȼ���һ������"+MONEY_D->money_num(this_object()->query("money_need"))+".\n"
                }) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge", 90);

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
       object ob,area;
       area=new("/obj/area");
	area->create(query("area_name"));
       set("banghui",(string)area->query("banghui"));
       destruct(area);
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_ask","ask");
}

int do_ask(string str)
{
	string banghui;
	object me;
	string sb,sth;

	if(! str)	return 0;

	me=this_player();

	if(! living(me))	return 0;

	if(sscanf(str,"%s about %s",sb,sth)!=2)	return 0;

	if(sb!=this_object()->query("id"))	return 0;

	if(sth!="�ݷ�") return 0;

	banghui=(string)me->query("banghui");

       if(! banghui || query("banghui")!=banghui)   {
		if((int)me->query_temp("have_asked")>=3)	{
		message_vision(HIG"\n$N"HIG"һ���۵���"+me->query("name")+HIG
		"���ʸ�û��û�ˣ������ǲ�����Ǯ����������ȥ���Ź����ʰɣ�\n\n"NOR,
		this_object());
		me->delete_temp("have_asked");
		kill_ob(me);
		me->fight_ob(this_object());
		return 1;
		}
		command("hehe");
		message_vision("$N˵������������"+me->query("name")+
		"�͸�(pay)��"+MONEY_D->money_num(this_object()->query("money_need"))+"�ɡ�\n",this_object());
		me->add_temp("have_asked",1);
		return 1;
	}
	message_vision("$N������$n�ļ��������ǰ����ֵܣ����Ļ�Ҫ���Ǯ�ء�\n",this_object(),me);
	return 1;
}

void greeting(object ob)
{
	string banghui;

	if( !ob || environment(ob) != environment() ) return;
       if( ob->query("env/invisibility") ) return;

	banghui=(string) ob->query("banghui");

       if(! banghui || query("banghui")!=banghui)   {
		say("���������һ����ͷ���˹�ȥ��\n"NOR);
		return;
		}
	command("say ��λ"+RANK_D->query_respect(ob)+"����������ɺã�\n");
	return;
}
/*
void die()
{
  if (environment())

  set("eff_kee", 200);
  set("eff_gin", 200);
  set("eff_sen", 200);
  set("kee", 200);
  set("gin", 200);
  set("sen", 200);
  set("force", 200);
  set("mana", 200);
}
*/
void unconcious() { die (); }

