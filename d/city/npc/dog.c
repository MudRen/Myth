// dog.c

inherit NPC;

void create()
{
	set_name("�ڹ�", ({ "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ���úܾ���ĺڹ���\n");
	
	set("str", 32);
	set("dex", 36);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: call_other, this_object(), "random_move" :),
		"�ڹ��ñ�����������Ľš�\n",
		"�ڹ�����Ľű߰��������ģ����ֶ����ԡ�\n",
		"�ڹ�������ҡ��ҡβ�͡�\n",
		"�ڹ��ú���ץ��ץ�Լ��Ķ��䡣\n" }) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "���˵���������������\n", environment());
		return 1;
	}
}
