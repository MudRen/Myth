// dog.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�����������Ұ����\n");
	
	set("str", 24);
	set("cor", 26);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set_temp("apply/attack", 10);
	set_temp("armor", 3);

	setup();
}
