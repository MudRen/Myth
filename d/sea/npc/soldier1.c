inherit NPC;

void create()
{
        set_name("Ϻ��", ({"xia bing", "xia"}));
        set("long","һ�����ſ��׵Ĵ�Ϻ�ף���������ȥά������\n");
        set("gender", "����");
        set("age", 14);
        set("per", 10);
        set("attitude", "heroism");
        set("combat_exp", 15000);
	set("max_kee", 250);
	set("max_sen", 250);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("unarmed", 20);
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
}

