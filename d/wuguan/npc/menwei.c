//Cracked by Roath
// by dubei
inherit NPC;
#include <ansi.h>
void create()
{
	int age = 20 + random(20);
	set_name("�������", ({ "men wei", "menwei", "wei" }));
	set("gender", "����");
	set("age", age);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set("apply/attack", 30);
	set("apply/defense", 30);
	set("apply/damage", 35);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	add_money("silver", 3+age/10);
	carry_object(__DIR__"obj/cloth")->wear();
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
	
void greeting(object ob)
{
	if( !ob || environment(ob) != environment()) return;
	if((ob->query("combat_exp") < 20000) && !ob->query("wuguan/join")) 
		command("say ��������ݹ����Ͳţ���λ" + RANK_D->query_respect(ob)+"�β�һ�ԣ�\n");
	if(ob->query("combat_exp") > 20000  && ob->query("combat_exp") < 80000 )
	{
		command("say �ɹ�Ŀǰ���ڹ����������ξ����������˲ţ���λ" + RANK_D->query_respect(ob)+"�书���и������β�ȥΪ��Ч����\n");
		if (ob->query("wuguan/join")) ob->delete("wuguan");
		message_vision(CYN"$N΢΢һЦ������˵������л׳ʿ��棬�����ǰȥ������˵�գ����Ӿ���׼��������ݡ�\n"NOR, ob);
	}
	if ( ob->query("combat_exp") > 80000)
	{
		command("hmm "+ob->query("id"));
		command("say ����ֻ�����������֣��㵽������ʲô������ͼ��");
	}
	return;
}
