// waiter.c

inherit NPC;

void create()
{
	set_name("˾��", ({ "driver", "siji" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���ҿ��������ϵ��Ʋ�ñ������һ�� ���ַ������������˯��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "ʦ��");
	setup();
	carry_object("/obj/cloth")->wear();
}

