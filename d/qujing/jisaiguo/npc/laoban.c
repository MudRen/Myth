inherit NPC;

void create()
{
       set_name("���ϰ�", ({"liu laoban", "laoban"}));
       set("gender", "����");
       set("age", 40);
        set("long", "һ���������֣�����Ц�ݵ�С�ϰ塣\n");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 20);
	set("str", 20);
       set("combat_exp", 8000);
        set_skill("unarmed", 15);
        set_skill("dodge", 15);
        set_skill("blade", 15);
        set_skill("parry", 15);
	set_skill("force", 15);
	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	add_money("silver", 2+random(3));
}

