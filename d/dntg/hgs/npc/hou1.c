// monkey1.c

inherit NPC;

void create()
{
	set_name("����", ({ "hou zi","monkey","hou" }) );
	set("race", "Ұ��");
	set("age", 8);
	set("long", "һֻ��Ƥ��С���ӡ�\n");
	
	set("str", 30);
	set("cor", 26);	
	set("combat_exp", 50);
  set("daoxing", 0);

            set_skill("dodge",20);
            set_skill("unarmed",10);
	set("limbs", ({ "ͷ��", "����", "ǰצ", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 3);
	set("chat_msg", ({
                (: call_other, this_object(), "random_move" :),
		"С���Ӹ��˵�ֱ�����\n",
		"�����Ǵ�е�����Ҫ���������ﰲ�Ҿͺ��ˡ���\n",
		"�����ǽ�ͷ�Ӷ����������������ǳ滢���������ҡ���\n"}) );
		

	setup();
}

�