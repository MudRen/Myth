inherit NPC;

void create()
{
        set_name("����", ({"wang lin", "wang"}));
        set("age", 32);
        set("gender", "����");
        set("long", "���̵��ϰ壬���Ļ���������\n");
        set("attitude", "peaceful");
	set("title", "�����ϰ�");
        set("combat_exp", 40000);
        set("shen_type", 1);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 50);
	set_skill("blade", 40);
	setup();
	add_money("silver", 10);
        carry_object("/d/obj/cloth/linen")->wear();
//        carry_object("/d/city/npc/obj/caidao")->wield();
}


