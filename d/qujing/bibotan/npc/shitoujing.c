inherit NPC;
void create()
{
        set_name("ʯͷ��", ({"shitou jing", "jing"}));
        set("long", "һ���������ɵĴ���ʯ��ֻ�Ƕ�����ֽź��Դ���\n");
        set("age", 30);
        set("attitude", "herosim");
        set("gender", "����");
	set("class", "yaomo");
        set("str", 30);
        set("int", 20);
        set("per", 10);
	set("looking", "�������¾���ʯͷ��������ʲô��ò��");
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
	set_temp("apply/armor", 100);
        set("combat_exp", 200000);
  set("daoxing", 150000);


	set("eff_dx", -100000);
        set("nkgain", 350);

        set("force", 600);
        set("max_force", 600);
        set("mana",300);
        set("max_mana",200);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 90);
        set_skill("force", 90);
        set_skill("spells", 90);
        set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("hammer", 90);
	set_weight(500000);
        setup();
	carry_object("/d/qujing/firemount/obj/stone")->wield();
}
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
	object stone;
	
	this_object()->add("time", 1);
	if( (int)this_object()->query("time") >= 8 ) {
        message("vision",name() + "���˸����������ɵ��ڵ��¡�\n", environment(),this_object() );
	seteuid(getuid());
	if(stone=new("/d/qujing/bibotan/npc/stone"))
	stone->move(environment(this_object()));
        destruct(this_object());

	}
	return;
}

void relay_emote(object ob,string verb)
{
        switch(verb) {
        case "kick":
                        command("say ���ߣ��������үս�����ٻغϡ�\n");
			this_object()->fight_ob(ob);
			ob->fight_ob(this_object());
                break;
        }
}

�