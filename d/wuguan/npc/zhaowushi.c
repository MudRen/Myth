//Cracked by Roath
// zhaowushi.c



inherit NPC;



#include <ansi.h>



int ask_kungfu();



void create()

{

        set_name("����ʦ", ({ "zhao wushi", "zhao","wushi" }));

        set("long", "����ʦ�ǹ����ĵ�������֮һ��\n");

        set("gender", "����");

        set("age", 45);

        set_skill("dodge", 80);

        set_skill("force", 80);

        set_skill("parry", 80);

        set_skill("claw", 80);

        set_skill("cuff", 80);

        set_skill("blade", 80);

        set_skill("stick", 80);

        set_skill("club", 80);

        set_skill("staff", 80);

        set_skill("sword", 80);

        set_skill("throwing", 80);

        set_temp("apply/attack", 80);

        set_temp("apply/defense", 80);

        set_temp("apply/damage", 20);

		set("inquiry",([

			"����":		(:ask_kungfu:),

			]));

        set("combat_exp", 400000);

        set("shen_type", 1);

        setup();

        carry_object(__DIR__"obj/cloth")->wear();

}



void init()

{

	object ob=this_player();

	

	::init();

	

	if(interactive(ob) && !is_fighting())

	{

		remove_call_out("greeting");

		call_out("greeting",1,ob);

	}

	return ;

}

		

int recognize_apprentice(object ob)

{

	if(!ob->query("wuguan/join")) return 0;

	if(ob->query("combat_exp")>30000)

	{

		command("shake");

		command("say ����书�Ѿ���һ�������ˣ�ȥ�Ҹ��߼���ʦ��ѧ�ɡ�"); 

		return 0;

	}

    return 1;	

}



void greeting(object ob)

{

	if( !ob || environment(ob) != environment() ) return;

	if(ob->query("combat_exp")>=30000) return;

	

	command("nod "+ob->query("id"));

	command("say " + RANK_D->query_respect(ob)

				+ "������Կ��һ�Ĺ���"HIY"(cha zhao)"NOR",���Ը���ѧ����"HIY"��xue zhao xxx)"NOR"��\n");

	return;

}



int is_apprentice_of() {return 1;}



int ask_kungfu()

{

	object ob=this_player();

	

	if(!ob->query("wuguan/join"))

	{

		command("say �ҵĹ���Ų��⴫��");

		return 1;

	}

	if(ob->query_temp("wuguan/kungfu"))

	{

		command("say ��������ֽ�һ����");

		command("consider");

		command("say ���аɣ�");

		ob->delete_temp("wuguan/kungfu");

		fight_ob(ob);

		return 1;

	}

	

	command("whisper "+ob->query("id")+

	" ���������ǽ�����������ǧ��ն���õ����ܶ��ؼ�����ȥ�鷿�������������ҵ���");

	ob->set_temp("wuguan/kungfu",1);

	return 1;

}

	
