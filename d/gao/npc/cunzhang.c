// leader.c

inherit NPC;

void create()
{
       set_name("����", ({"wu wen", "wen", "wu"}));
       set("long","һ�����������з�ȵ������ˣ��������й䣮\n");
       set("gender", "����");
	set("title", "�峤");
       set("age", 46);
	set("combat_exp", 8000);
	set_skill("unarmed", 15);
	set_skill("dodge", 15);
	set_skill("parry", 15);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("chat_chance", 10);
set("inquiry", ([

"name"  : "�Ϸ����⣬����һ�����֣�",
"here"  : "���������������𣿺ٺ٣�����",

]));
        set("chat_msg", ({
            "�峤�������´������㼸�ۡ�\n",
            (: random_move :)
        }) );

	setup();
	add_money("silver", 2);
        carry_object("/obj/cloth")->wear();

}


