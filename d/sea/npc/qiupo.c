inherit NPC;

void create()
{
       set_name("����", ({"qiupo"}));

set("long","һλ�����ţ�����Ů���������ˣ�\n");
       set("gender", "Ů��");
       set("age", 56);
	set("per", 20);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set_skill("unarmed", 50);
	set_skill("dodge", 80);
	set_skill("parry", 40);
        set("combat_exp", 26000);
  set("daoxing", 50000);

        setup();
        add_money("silver", 1);
//        carry_object("/d/gao/obj/blade")->wield();

}

�