inherit NPC;
string fan_me(object me);

void create()
{
        set_name("������", ({"li yuniang", "li"}));
        set("age", 28);
        set("gender", "Ů��");
        set("long",
"��������Ԭ������ţ�����ϴ��������\n");
        set("attitude", "friendly");
	set("per", 25);
        set("combat_exp", 4000);
  set("daoxing", 20000);

        set("shen_type", 1);
        set_skill("unarmed", 20);
	set_skill("parry", 20);
        set_skill("dodge", 40);
        set("inquiry", ([
"Ԭ���": "�������ˣ���ô����Ҳ���ؼҳԷ���Ҳ�Ҳ������˰ѷ���ȥ��\n",
"�ͷ�": (: fan_me :),
]));

	setup();

        carry_object("/d/obj/cloth/pink_cloth")->wear();
	carry_object("/d/city/obj/fanhe");
}
string fan_me(object me)
{	object who;
	who=this_player();
	
	if(!present("fan he", me)){
	return "�����·Զ�ģ����˰ɣ���л�ˣ�\n";
	}
	if(present("fan he", me)){
	command("give fan to " + who->query("id"));
	return "��л�ˣ���ȥ�ɣ�";
	}
}
�