inherit NPC;

void create()
{
        set_name("�����", ({"xiucai"}));
        set("age", 22);
        set("gender", "����");
        set("long",
"���Ӽ����ѧ����������ʫ������\n");
        set("attitude", "peaceful");
	set("per", 22);
        set("combat_exp", 8000);
        set("shen_type", 1);
        set("class", "scholar");
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 3);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("changquan", 20);
	map_skill("unarmed", "changquan");
        set("chat_chance", 4);
        set("chat_msg", ({
"����ŵ���������һ�������壬��ɽ���ϻ�����ʫ����ʫѽ��\n",
"����ų�̾һ���������Ҳű����ã���ϧ��������ʱ��\n",

}) );
	setup();

        carry_object("/d/gao/obj/changpao")->wear();
}
int accept_fight(object me)
{
        command("say ����������Ų����Ż����磬�书Ҳ�����ж��֣�\n");
        return 1;
}

