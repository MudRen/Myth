// guanjia.c

inherit NPC;

void create()
{
       set_name("����", ({"gao zheng", "gao"}));
       set("long","�ϸ߼ҵĹܼң��������ʲ����ʣ�\n");
       set("gender", "����");
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("title", "�Ϲܼ�");
	set("combat_exp", 6500);
       set_skill("unarmed", 15);
	set_skill("dodge", 15);
	setup();
       add_money("silver", 5+random(8));
        carry_object("/d/gao/obj/magua")->wear();

}
int accept_fight(object me)
{
        command("say �����Ҳ�ã�\n");
        return 1;
}

