//created by greenwc
//created by greenwc
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("����������", ({"dashizhi pusa", "dashizhi", "dashi", "pusa"}));
  set ("long", @LONG
���ް����ӷ��ͽ��������������ʦ�ܣ���
�˲�����������
LONG);
  set("title", "��������֮");
  set("gender", "����");
  set("age", 400);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
       set_skill("literate", 150);
	set_skill("spells", 180);
	set_skill("buddhism", 180);
	set_skill("unarmed", 160);
	set_skill("jienan-zhi", 160);
	set_skill("dodge", 150);
	set_skill("lotusmove", 170);
	set_skill("parry", 150);
	set_skill("force", 180);
	set_skill("lotusforce", 180);
	set_skill("hammer", 180);
	set_skill("bighammer", 180);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "bighammer");
	map_skill("hammer", "bighammer");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
                      	(: perform_action, "hammer", "dashi" :),
	}) );
           set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

	create_family("�Ϻ�����ɽ", 1, "����");
  setup();

	carry_object("/d/obj/weapon/hammer/falun2")->wield();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

int accept_fight(object me)
{
  command("say ʩ����Ц��\n");
return 0;
}

int attempt_apprentice(object ob)
{
	string myname=RANK_D->query_respect(ob);
            if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
return 0;
}
if ((int)ob->query_skill("buddhism")< 100) 
{
      command("say ʩ���Է𷨵��о����������");
return 0;
}
	command("pat " + ob->query("id") );
	command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");
	command("recruit " + ob->query("id") );
        return 0; 
}

void die()
{
        if( environment() ) {
        message("sound", "\n\n����������ҡͷ̾����ԩ��������ԩ����n\n", environment());
        command("sigh");
        message("sound", "\n���������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());
}

	destruct(this_object());
}
