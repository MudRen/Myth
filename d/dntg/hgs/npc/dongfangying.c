inherit NPC;

void create()
{

        set_name("����Ӣ", ({ "dongfang ying", "dongfang", "ying"}) );
        set("gender", "Ů��");
        set("age", 22);
	set("per", 25);
        set("long", "����Ӣ�ǹ����Ķ���Ů���书�ָߣ�����Ư����\n");
        set("combat_exp", 18000);
	set("title", "��ݽ�ͷ");
	set_skill("sword", 50);
	set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_skill("force", 40);
        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/pink_cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

int recognize_apprentice()
{
        if(!this_player()->query("newbie/learn") )
        return notify_fail("����Ӣ���ߵ�һЦ����Ҫ�ǲ�ͬ�⣬�ҿɲ��ҽ̡�\n");

        return 1;
}

