
inherit NPC;

void create()
{
       set_name("����", ({"hua jiang", "jiang"}));
       set("long", "������ݵĻ�����������ˮ������\n");
       set("gender", "����");
        set("combat_exp", 1000);
	set("per", 18);
       set("age", 26);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        setup();
       add_money("silver", 5);
}

