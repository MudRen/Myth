
inherit NPC;

void create()
{
       set_name("����", ({"woman"}));
       set("gender", "Ů��");
        set("combat_exp", 500);
	set("per", 19);
       set("age", 36);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 5);
        setup();
       add_money("silver", 1);
}

