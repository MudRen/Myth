//Cracked by Roath
// zhike.c ֪��ɮ�
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("֪��ɮ", ({ "zhike seng", "seng" }));
	set("long", "һλ�����ɮ�ˣ��������Ǵ��������Ц�ݡ�\n�������ڴ�ӭ��ǰ����������Ŀ��ˡ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);

	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

        create_family("�Ϻ�����ɽ", 4, "����");
	
	setup();
              add_money("silver", 8); 
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
	&& !ob->query("env/invisibility") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "֪��ɮ�����˵������λ" + RANK_D->query_respect(ob) + "����ӭ�����Ϻ�����ɽ��\n");
}

�
