//Cracked by Roath
//qingfeng.c

inherit NPC;
void create()
{
	set_name("���", ({"qing feng", "qingfeng"}));
	set("gender", "����" );
	set("age", 16);
	set("long", "һ�������С��ͯ������ׯ�����º��ǳԵÿ���\n");
	set("class", "xian");
	set("combat_exp", 10000);
  set("daoxing", 20000);

	set("attitude", "peaceful");
	set("title", "С��ͯ");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	set("per", 20);
	set("max_kee", 200);
	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
}

void init()
{       
	object ob=this_player();
	object me=this_object();

	::init();

	if ( ((int)ob->query("env/invisibility")  == 0) && ((string)environment(me)->query("short")=="����") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if ( (int)ob->query("combat_exp")>500000 )
		command("say ��λ" + RANK_D->query_respect(ob) + "ʧӭ�ˣ������������뵽��������裡\n");
	else if ( (int)ob->query("combat_exp")>100000 )
		command("say ��λ" + RANK_D->query_respect(ob) + "ʧӭ�ˣ����������뵽�����ò裡\n");
	else if ( (int)ob->query("combat_exp")>10000 )
		command("say ��λ" + RANK_D->query_respect(ob) + "���������ò裡\n");
	else if ( (int)ob->query("combat_exp")>1000 )
		command("hi " + ob->query("id"));	
	else
		return;
}
�