inherit NPC;

void create()
{
       set_name("������", ({"suoming gui", "gui"}));
       set("gender", "����");
       set("age", 30);
	set("long", "һ�����������С������Ƥ���ֳ�������
����������Ǵ����佫���˵Ļ��Ǵ��أ�\n");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 60000+random(30000));
  set("daoxing", 30000);

	set("bellicosity", 300);
	set_skill("unarmed", 65);
	set_skill("dodge", 65);
	set_skill("whip", 65);
	set_skill("parry", 45);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 15);
	set("max_kee", 450);
set("inquiry", ([
"here": "��������ܵظ����ߣ����Ű�Ƥ�����㣡\n",
]) );

set("chat_chance", 8);
set("chat_msg", ({
"��������������´������㼸�ۡ�\n",
"������˵���������������������������㵽�����\n",
(: random_move :)
}) );

setup();

        carry_object("/d/obj/cloth/shoupi")->wear();
        carry_object("/d/obj/weapon/whip/tielian")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
	
	if ((string)ob->query("family/family_name")!="���޵ظ�") {
	if (random((int)ob->query("age")) > 20 ){
	command("tell " + ob->query("id") + " ����ү����������Ļ꣬��ȴ�Լ����������������߰ɣ�\n");
	kill_ob(ob);
	set_leader(ob);
	return;
	}
	return;
	}
return;
}
return;
}

int accept_fight(object me)
{
        command("say ���ò��ͷ��ˣ�\n");
        kill_ob(me);
        return 1;
}

�