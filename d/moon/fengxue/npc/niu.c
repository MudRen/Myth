// niu.c
// 1996/10/31 by none

inherit NPC;

void create()
{
	set_name("��ѩ�ʺ�", ({ "queen" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("per", 25);
	set("long",
		"�������Σ���÷��ѩ��������Σ�������˪��
�侲���Σ������չȡ��������Σ�ϼӳ������
�������Σ��������ӡ��������Σ����亮����\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "��ѩ��ػʺ���Ҳ��",
		"here" : "��ѩ֮�ϣ����֮�С�",
	]) );
	set_skill("literate", 100);
	setup();
	carry_object("/d/obj/cloth/skirt.c")->wear(); 
	carry_object("/d/obj/cloth/shoes")->wear();
}

