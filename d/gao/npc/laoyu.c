// laoyu.c

inherit NPC;

void create()
{
       set_name("����ͷ", ({"laoyu"}));
       set("long", "�ϸ߼ҵĿ����ˣ����ڴ��˯��\n");
       set("title", "���Ŵ�ү");
       set("gender", "����");
	set("combat_exp", 100);
       set("age", 56);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 15);
	setup();
       add_money("silver", 5);
}

