//puti.c
inherit NPC;

void create()
{
       set_name("����ʹ��", ({"bridge guard", "guard"}));
       set("gender", "����");
       set("age", 25+random(10));
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("max_kee", 400);
       set("max_gin", 400);
       set("max_sen", 400);
       set("force", 450);
       set("max_force", 400);
       set("force_factor", 20);
       set("max_mana", 100);
       set("combat_exp", 40000+random(10000));
       set_skill("unarmed", 40);
       set_skill("dodge", 50);
       set_skill("parry", 50);
	set_skill("whip", 50);
        set_skill("force", 50);

setup();

        carry_object("/d/obj/cloth/choupao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/obj/weapon/whip/whip")->wield();
}

int accept_fight(object me)
{
        command("say ���ò��ͷ��ˣ�\n");
        kill_ob(me);
        return 1;
}

