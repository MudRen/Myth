// monkey1.c

inherit NPC;

void create()
{
	set_name("�����", ({ "mahou","monkey","hou" }) );
	set("race", "Ұ��");
	set("age", 26);
	set("long", "һֻ����\n");
	
	set("str", 35);
	set("cor", 26);	
	set("combat_exp", 5000);
  set("daoxing", 2000);

  

            set_skill("dodge",40);
            set_skill("unarmed",30);
	set("limbs", ({ "ͷ��", "����", "ǰצ", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: call_other, this_object(), "random_move" :),
		"�����������˸�������\n",
		"ž��һ�������������һ��Ұ��������������ı��ӡ�\n",
		"��������֨֨֨�ؽ��˼�����\n",
		"�����ץ�������أ�Χ����������ȥ��\n" }) );
		
//	set_temp("apply/attack", 20);
//	set_temp("apply/defense", 50);
//	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("mihou tao")||ob->id("huasheng")||ob->id("jiudai")) {
		set_leader(who);
		message("vision", name() + "���˵�ץ��������ֱ����ͷ��\n", environment());
		return 1;
	}
}
��