// lanling_yuhuayuan.c

inherit NPC;

void create()
{
        set_name("吴忧", ({"wu you","wuyou"}));
        set("title", "守护使者");
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个气宇不凡的大汉,据说是月宫吴刚的表弟.");
        set("combat_exp", 200000);
      set("daoxing", 500000);

        set("attitude", "peaceful");

        set("eff_dx", 40000);
        set("nkgain", 200);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("literate", 120);
        set_skill("force", 100);   
        set_skill("axe", 100);
        set("per", 37);
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 25);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/moon/obj/bigaxe")->wield();
}

int accept_fight(object me)
{
        command("ya");     
        command("say 砍掉吧,我反正也不想天天傻守着了。");
        return 1;
}
