// worker.c

inherit NPC;

void create()
{
        set_name("ɨ��Сͯ", ({"xiao tong"}));
        set("gender", "����" );
        set("age", 13);
        set("long", "һ��Сͯ�����������ɨ��");
        set("combat_exp", 1000);
	set_skill("stick", 20);
	set_skill("dodge", 40);
        set("attitude", "friendly");
        set("chat_chance_combat", 50 );
        setup();
	carry_object("/d/lingtai/obj/shaoba")->wield();
}
