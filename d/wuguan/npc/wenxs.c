//Cracked by Roath
// zhu.c ������

inherit NPC;

#include <ansi.h>

int ask_zixue();

void create()
{
	set_name("������", ({ "wen xiansheng", "teacher","wen","xiansheng" }));
	set("long",
"����������Ϊ�������������Щīˮ���ˡ�\n");
	set("gender", "����");
	set("age", 65);
	set_skill("literate", 60);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);
	set("combat_exp", 80000);
	set("shen_type", 1);
	set("inquiry",([
		"��ѧ":		(:ask_zixue:),
		]));
	
	setup();
}

void init()
{
	object ob=this_player();
	::init();
	
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	return;
}

int recognize_apprentice(object ob)
{
	int money=25, level = ob->query_skill("literate", 1);

	if(level>30) money=50;
	if(level>50) money=100;
	if(level>100) money=500;
	if(level>150) money=800;
	if(level>200) money=1000;
	if(level>250) money=1500;

	if(!ob->query("wuguan/join")) return 0;
	ob->delete_temp("mark/literate");
	switch(MONEY_D->player_pay(ob, money))
	{
		case 0:
		case 2:
			tell_object(ob,"�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��\n");
			return 1;
			break;
	}
	ob->set_temp("mark/literate",1);
	return 1;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob->query_skill("literate") > 60 ) return;
	
	command("pat "+ob->query("id"));
	command("say ��λ" + RANK_D->query_respect(ob)


                                + "��������ѧЩ֪ʶ"HIY"(xue wen literate)"NOR"�ɡ�");
}

int is_apprentice_of()
{
	return 1;
}

int ask_zixue()
{
	object ob=this_player();
	
	if(!ob->query("wuguan/join"))
	{
		command("say �㲢������ݵĳ�Ա��Ҫ����ѧҲ������ѽ��");
		return 1;
	}
	if(ob->query_skill("literate",1)<10)
	{
		command("say �������ä��������ѧ��");
		return 1;
	}
	if(ob->query_skill("literate",1)<60)
	{
		command("say �������ˮƽ������ѧʲô��");
		return 1;
	}
	if(ob->query_temp("wuguan/zixue"))
	{
		command("say ��������Ҳ��Ǹ��������ô����ô�����ʣ�");
		command("walkby "+ob->query("id"));
		command("say ��������ˮƽҲ����ѧ��");
		return 1;
	}
	
	command("whisper "+ob->query("id")+
	" �鷿����Щ�飬�������ڵ�������Ӧ���ܿ�������ȥ���Ұɡ�");
	ob->set_temp("wuguan/zixue",1);
	return 1;
}
	
