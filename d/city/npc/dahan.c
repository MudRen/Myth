inherit NPC;

void create()
{
        set_name("�±���", ({"dahan"}));
        set("age", 25);
        set("gender", "����");
        set("long",
"һ�����Ϳ���Ĵ󺺣����ڳ԰��ӡ�\n");
        set("attitude", "peaceful");
	set("str", 30);
        set("combat_exp", 12000+random(3000));
        set("shen_type", 1);
        set("force", 200);
        set("force_factor", 3);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
int accept_fight(object me)
{
        command("say ��ܣ�����С�ĵ㣬Ī���ϰ���������ˣ�");
        return 1;
}


