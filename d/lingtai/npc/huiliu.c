// worker.c

inherit NPC;
void create()
{
        set_name("����", ({"hui liu"}));
        set("gender", "����" );
        set("age", 33);
        set("long", "һ����ò���õĵ�ʿ��");
	set("title", "����");
	set("class", "taoist");
        set("combat_exp", 45000);
	set("daoxing", 60000);

        set("attitude", "peaceful");
        create_family("����ɽ���Ƕ�", 4, "����");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("force", 30);   
        set_skill("wuxiangforce", 30);
        map_skill("force", "wuxiangforce");

        set("per", 30);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 5);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

�
