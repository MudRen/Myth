//Cracked by Roath
// tieguaili.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
	set_name("������", ({"tieguai li", "tieguai", "li"}));
	//set("title", "");
	set("gender", "����" );
	set("age", 42);
	set("per", 12);
	set("long", "���ŵ�һ˫�ò�Ь������һ�����û�˱�����Ŀ�����ۣ���������ߵ�С����һ��������̬��\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 300000);

	set("attitude", "peaceful");
	create_family("��ׯ��", 3, "����");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 80);
	set_skill("parry", 80);
	set_skill("staff", 90);
	set_skill("fumo-zhang", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 20);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("staff", "fumo-zhang");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	carry_object("/d/obj/cloth/pobuyi")->wear();
	carry_object("/d/obj/cloth/lancaoxie")->wear();
	carry_object("/d/obj/weapon/staff/tieguai")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="��ׯ��" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
			else command("say ʦ�ü�Ц�ˡ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			command("kick " + ob->query("id") );
			command("say �����" + RANK_D->query_rude(ob) + "��������ǲ���ӣ�\n");
		}
		else 
		{
			command("consider");
			command("say �����Լ�Ҫ�ݵģ���ʦ�����������ҿɵ����㵲��\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say �ã�����ׯ��һ���˲ű�������ɵø�ʦ��������\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}




�