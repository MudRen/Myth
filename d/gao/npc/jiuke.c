// jiading.c

inherit NPC;

void create()
{
       set_name("�ƿ�", ({"jiuke"}));

set("long","�ȵ�����ͨ�죬���������һ����������\n����Ǻȵ�̫���ˣ��۾��Ĵ���ţ����������첻֪˵Щʲô��\n");
	set("bellicosity", 500);
       set("gender", "����");
       set("age", 36);
       set("attitude", "heroism");
       set("shen_type", 1);
	set("combat_exp", 10000);
	set("force", 200);
	set("max_force", 200);
	set_skill("parry", 25);
	set_skill("dodge", 35);
	set("force_factor", 3);
	setup();
        add_money("silver", 1);
        carry_object("/obj/example/dagger")->wield();
        carry_object("/obj/cloth")->wear();
}
int accept_fight(object me)
{
        command("say ��ܣ����ӵ����鳤���޵��֣�");
        return 1;
}

