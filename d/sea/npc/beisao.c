inherit NPC;

void create()
{
       set_name("��ɩ", ({"beisao"}));

set("long","һλ���긾Ů������Ů���������ˣ�\n");
       set("gender", "Ů��");
       set("age", 36);
	set("per", 20);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set_skill("unarmed", 60);
	set_skill("dodge", 80);
	set_skill("parry", 60);
        set("combat_exp", 36000);
        setup();
        add_money("silver", 1);

}

