inherit NPC;

void create()
{
        set_name("�����˵�", ({"seller"}));
        set("age", 42);
        set("gender", "����");
        set("long",
"һ�������˵ģ����������˶�С����\n");
        set("attitude", "peaceful");

        set("combat_exp", 2000);
        set("shen_type", 1);

        set_skill("dodge", 20);
        set_skill("parry", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
"�����˵ĺ���������������ˣ�������ѽ��\n",
"�����˵ĺ���������������ˣ�����һ����\n",
(: random_move :)
}) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


