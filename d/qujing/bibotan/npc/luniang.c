inherit NPC;
void create()
{
        set_name("«��", ({"lu niang"}));
        set("long",
"��ͷ�ϲ��ż����ɫ«����������Ȼ������ȴ�ڲ�ס���ϵ�������\n");
        set("age", 20);
	set("title", "«����");
        set("attitude", "friendly");
        set("gender", "Ů��");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);
        set("combat_exp", 160000);
  set("daoxing", 100000);


	set("eff_dx", -60000);
        set("nkgain", 330);

        set("force", 600);
        set("max_force", 600);
        set("mana",300);
        set("max_mana", 500);
        set("force_factor", 30);
        set("mana_factor", 20);
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("spells", 80);
        set_skill("dodge", 100);
	set_skill("parry", 80);
	set_skill("whip", 80);
	set_skill("moondance", 80);
	set_skill("snowwhip", 80);
	map_skill("whip", "snowwhip");
	map_skill("parry", "snowwhip");
	map_skill("dodge", "moondance");
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/qujing/bibotan/obj/luhua")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
	
	if((string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�" 
	&& (string)ob->query("family/family_name")=="��ʯɽ�̲�̶"
        && (string)ob->query("family/family_name")=="��ѩɽ") {
	command("xixi " + ob->query("id"));
	return;
	}
	command("look " + ob->query("id") );
	command("say �ְ����֣���������θ�ڡ�");
	command("chan " + ob->query("id") );
	kill_ob(ob);
	ob->fight_ob(this_object());

	return;
}

�