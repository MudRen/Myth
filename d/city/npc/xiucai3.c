inherit NPC;

void create()
{
        set_name("�����", ({"xiucai"}));
        set("age", 62);
        set("gender", "����");
        set("long",
"���Ӽ����ѧ����ͷ���԰ף��������档\n");
        set("attitude", "friendly");
	set("per", 22);
        set("combat_exp", 1000);
        set("shen_type", 1);
        set("class", "scholar");
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }));

	setup();

        carry_object("/d/gao/obj/changpao")->wear();
}
