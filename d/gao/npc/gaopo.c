// gao.c

inherit NPC;

void create()
{
       set_name("����", ({"gao po", "gao", "po"}));
       set("long","��ׯ�������ţ�������ʮ���꣬���������ּ�����ɫ��\n");
       set("gender", "Ů��");
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("per", 20);
	set("combat_exp", 7400);
        set_skill("unarmed", 10);
	set_skill("dodge", 50);
	set_skill("parry", 20);
	setup();
        add_money("silver", 20);
        carry_object("/d/gao/obj/ao")->wear();

}

