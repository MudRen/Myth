inherit NPC;

void create()
{
       set_name("������̫̫", ({"lao taitai", "woman"}));
       set("long", "һ��Զ�������㻹Ը����̫̫��\n");
	set("looking", "�����ط磬��ͷ�׷���");
       set("gender", "Ů��");
        set("combat_exp", 500);
       set("age", 78);
	set("kee", 200);
	set("sen", 200);
	set("gin", 200);
       set("attitude", "peaceful");
       set("shen_type", 1);
        setup();
        carry_object("/obj/cloth")->wear();
       add_money("coin", 40+random(30));
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 30);
        set("chat_msg", ({
            "��̫̫̾�ɿ�����\n",
            "��̫̫˵�����Ը��ȻҪ���\n",
        }) );
}

