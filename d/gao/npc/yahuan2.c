// yahuan1.c

inherit NPC;

void create()
{
       set_name("СѾ��", ({"yahuan"}));
       set("long","һ��СѾ�������ź����ү��\n");
       set("gender", "Ů��");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
	set("combat_exp", 100);
	setup();
        carry_object("/d/gao/obj/pink_cloth")->wear();
}

