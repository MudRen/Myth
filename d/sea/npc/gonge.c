inherit NPC;

void create()
{
       set_name("����", ({"gong e", "e"}));

	set("long","һ��СѾ����\n");
       	set("gender", "Ů��");
	set("str", 20);
       	set("age", 16);
       	set("attitude", "peaceful");
        set("combat_exp", 400);
        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();

}

