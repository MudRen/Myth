//Creat by waiwai@2001/05/12


inherit NPC;

void create()
{
        set_name("���峾", ({ "qing_chen" }) );
        set("age", 20);
	  set("gender", "Ů��");
	  set("title", "���鸮С��");
        set("long",
                "�������鸮��ǧ��ƽʱһֱ�����Լ����巿�������Ȼ���\n"
		"���ʢ�����������ε����š���磬ȴ�������ܼ��������ˡ�\n"
		"��֪�Ӻ�ʱ���������������������һ�н������š�\n"
                );

        set("attitude", "peaceful");

        set("per", 27);
	  set("int", 30);

        set("force", 500);
        set("max_force", 300);
        set("force_factor", 20);

        set("mana", 2000);
        set("max_mana", 1000);
        set("mana_factor", 3);


        set("combat_exp", 70000);

        set_skill("literate", 90);
        set_skill("force", 50);
        set_skill("spells", 70);
        set_skill("sword", 40);
        set_skill("parry", 40);
        set_skill("dodge", 60);

        setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}


