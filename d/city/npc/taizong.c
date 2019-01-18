#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"��̫��"NOR, ({ "tang taizong", "tang", "emperor" }));
	set("gender", "����");
	set("age", 50);
	set("per", 30);
	set("str", 20);
	set("dex", 20);
	set("long", "��̫�������񣬷���Ӣΰ�����Ķ��ꡣ\n");
	set("combat_exp", 60000);
	set("attitude", "heroism");
	set("rank_info/respect", "����ү");
	set("rank_info/rude", "�޵����");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("force", 500); 
	set("max_force", 500);
	set("enforce", 10);

	setup();
        carry_object("/d/obj/cloth/longpao")->wear();
        add_money("gold", 1);

}
