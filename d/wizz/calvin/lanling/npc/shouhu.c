// lanling_yuhuayuan.c

inherit NPC;

void create()
{
        set_name("����", ({"wu you","wuyou"}));
        set("title", "�ػ�ʹ��");
        set("gender", "����" );
        set("age", 35);
        set("long", "һ��������Ĵ�,��˵���¹���յı��.");
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
        command("say ������,�ҷ���Ҳ��������ɵ�����ˡ�");
        return 1;
}
