//Cracked by Roath
// xiaosi.c С��
// writen by kittt
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("С��", ({"xiao si", "xiao", "si"}));
	set("gender", "����");
	set("age", 18);
	set("long", 
	"����һ���о���С�ˣ����첻����ҵ�������й䣬ר������ \n"
      "һЩС����Ϣ�ͽ������š� \n" );
	set("shen_type", -1);
	
	set("chat_chance", 10);
	set("chat_msg", ({
	CYN"С��˵����������������ѧ�����ѽ����Ҳ�е���ȥ�ˡ���\n"NOR,
	CYN"С�˴�����������񴳵�������ȫƾȭͷ˵���� ��\n"NOR,
	CYN"С�������룬�ֵ��������Ǳ�ȥ����ˣ�ѧ�����ջ��øɻ�ۡ���\n"NOR,
	CYN"С����������ض���˵������˵������ݹ�����ȥ��Ž���ǧ��ն����\n"NOR  
}));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
      set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 1000);
	 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}

