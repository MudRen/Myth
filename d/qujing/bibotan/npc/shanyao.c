inherit NPC;
void create()
{
        set_name("ɽ��", ({"shan yao", "yao"}));
        set("long", "һ�������ɷ���ɽ����\n");
        set("age", 30);
        set("attitude", "herosim");
        set("gender", "����");
	set("class", "yaomo");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);
        set("combat_exp", 50000);
  set("daoxing", 50000);


	set("eff_dx", -20000);
        set("nkgain", 200);

        set("force", 200);
        set("max_force", 200);
        set("mana",100);
        set("max_mana", 100);
        set("force_factor", 20);
        set("mana_factor", 10);
        set_skill("unarmed", 40);
        set_skill("force", 40);
        set_skill("spells", 40);
        set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("wuhu-blade", 40);
	map_skill("blade", "wuhu-blade");
	map_skill("parry", "wuhu-blade");
        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
	carry_object("/d/obj/weapon/blade/kandao")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 40, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
	
	command("look " + ob->query("id") );
	command("say �ְ����֣��պ��������¾ƣ�");
	command("chan " + ob->query("id") );
	kill_ob(ob);
	ob->fight_ob(this_object());

	return;
}

�