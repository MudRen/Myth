//Cracked by Roath
// guanjia.c �ܼ�
// writen by kittt

inherit NPC;

void create()
{
	set_name("�ܼ�", ({"guan jia", "guan", "jia"}));
	set("gender", "����");
	set("age", 35);
	set("long", 
      "������ݵĹܼң��Թ������Ĺ���������ȴ���� \n" 
	"����������Ц����Ҷ�������ɥ����\n" );
	set("shen_type", -1);
	
	set("chat_chance", 20);
	set("chat_msg", ({
	"�ܼҴ���˵��������Ҽ��͸�ѽ����͵������\n",
	"�ܼ���ɫһ�������������ҿ���˭͵�����ɱ���Ҳ����顣 ��\n",
	"�ܼҶ���Ц�������봳������������㱾�¿ɲ��У�", (:random_move :) 
}));
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
      set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 1000);
	 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}

