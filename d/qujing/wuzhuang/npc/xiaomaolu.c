//Cracked by Roath
// xiaomaolu.c

inherit NPC;

void create()
{
	set_name("Сë¿", ({"xiao maolu", "maolu", "lu"}));
	set("race", "Ұ��");
	set("age", 10);
	set("combat_exp", 10000);
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite"}));

	set("ride/msg", "����");
	set("ride/dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 20);

	setup();
}


