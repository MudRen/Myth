inherit NPC;

void create()
{
       set_name("����", ({"long po"}));

set("long","���������ţ�������̫��\n");
       set("gender", "Ů��");
       set("age", 26);
	set("per", 30);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 126000);
  set("daoxing", 200000);

	set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 60);
	set_skill("dragonstep", 40);
	map_skill("dodge", "dragonstep");
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 3);
        setup();
        add_money("silver", 20);
        carry_object("/d/obj/cloth/jinpao")->wear();

}

�
