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
		"С�������ٲ���������һ�¡�\n",
		"�����ǽ�ͷ�����������֪���ٲ����Ƿ�ʲô�羰����\n",
		"�����ǵ�������һ���б��µģ����ȥѰ��Դͷ���������������ߣ��ҵȼ�����Ϊ������\n",
		"�ں����ֳ����������ˮ����ˮ��ԭ���˴�Զͨɽ��֮�£�ֱ�Ӵ�֮������\n" }) );
		

	setup();
}


��