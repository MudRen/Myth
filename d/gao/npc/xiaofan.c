
// laoyu.c

inherit NPC;

void create()
{
       set_name("С��", ({"xiaofan"}));
       set("long", "һ�������������ܸɵ�С����\n");
       set("gender", "����");
	set("combat_exp", 1500);
       set("age", 28);
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
        set("chat_chance", 10);
        set("chat_msg", ({
            "С�����˸����磮\n",
            "С���������´������㼸�ۡ�\n",
	    (: random_move :)
        }) );
}

