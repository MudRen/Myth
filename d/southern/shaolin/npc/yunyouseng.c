//xiaozuanfeng.c

int ask_name(); 

inherit NPC;
void create()
{

	set_name("����ɮ��", ({"yunyou seng", "seng"}));
	set("gender", "����" );
	set("age", 35);
	set("long", "һλ����ɮ�ˣ���������������������\n");
	set("class", "bonze");
	set("attitude", "peaceful");

        set("force", 1200);
        set("max_force", 700);
        set("force_factor", 20);
        set("mana", 1200);
        set("max_mana", 700);
        set("mana_factor", 20);
        set("combat_exp", 300000);
        set("daoxing", 500000);

	set_skill("jienan-zhi", 90);
	set_skill("lotusforce", 90);
	set_skill("buddhism", 90);
	set_skill("spells", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
        map_skill("unarmed", "jienan-zhi");
        map_skill("parry", "jienan-zhi");
        map_skill("force", "lotusforce");
        map_skill("spells", "buddhism");

	set("per", 21);
	set("max_kee", 800);
	set("max_sen", 800);
	setup();
	carry_object("/d/nanhai/obj/sengpao.c")->wear();

       set("inquiry", ([
                "name"     : "���·����Ѿ��ǲ����ˡ�",
         ]) );

        set("chat_msg", ({
            (: random_move :),
        }) );
        set("chat_chance", 15);

}


