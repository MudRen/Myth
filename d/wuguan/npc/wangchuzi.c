//Cracked by Roath
// wangchuzi.c ������

#include <ansi.h>


inherit NPC;

void destruct_fish(object me,object obj);

void create()
{
	set_name("������", ({ "wang chuzi","wang" }));
	set("long", 
		"��������֣��������������ĳ��ӡ�\n"
		"��Ȼ�������ķ��˱Ȳ��ϻʹ����ɽ��\n"
		"��ζ�����ڰ�������ȴҲ�������ġ�\n"
		);
	set("gender", "����");
	set("age", 32);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/qingcloth")->wear();
}

int accept_object(object ob,object obj)
{
	object me=this_object();
	
	return JOB_OB("wuguan")->give_fish(me,ob,obj);
}
