inherit NPC;

void create()
{
        set_name("�����", ({"xiucai"}));
        set("age", 22);
        set("gender", "����");
        set("long",
"���Ӽ����ѧ����������ʫ������\n");
        set("attitude", "friendly");
	set("per", 22);
        set("combat_exp", 4000);
        set("shen_type", 1);
        set("class", "scholar");
        set_skill("unarmed", 30);
        set_skill("dodge", 10);
        set("chat_chance", 4);
        set("chat_msg", ({
"����Ź�����Ц����֪�뵽��ʲô��\n",
"����ų�ü�����ģ�\n",

}) );

	setup();

        carry_object("/d/gao/obj/changpao")->wear();
}
