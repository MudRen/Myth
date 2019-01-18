//Cracked by Roath
// liwushi.c

inherit NPC;

#include <ansi.h>
void create()
{
        set_name("����ʦ", ({ "li wushi", "li","wushi" }));
        set("long", "һ������ڵĽ�ͷ��ר�Ÿ�������ֿ����书��\n");
        set("gender", "����");
        set("age", 42);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("sword",80);
        set_skill("stick", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

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
				+ "������Կ��һ�Ĺ���"HIY"(cha li)"NOR",���Ը���ѧ����"HIY"��xue li xxx)"NOR"��\n");
	return;
}

int is_apprentice_of() {return 1;}
