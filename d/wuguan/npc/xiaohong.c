//Cracked by Roath
// xiaohong.c С��
// by yfeng

#include <ansi.h>

inherit NPC;
int give_tea();

void create()
{
	set_name(HIM"С��"NOR, ({"xiao hong","ya huan","yahuan" }));
	set("long", 
"���������˲���ˮ��С���ˮ����Ĵ��۾���
���������ÿɰ�����˵����ǰ���ڼ���ˮ�֣���
����ʧɢ���Һ�������������������������Ȼ��
һ���˲���ˮ��СѾ�ߣ�����������ȴ��Ů��һ
����\n"
		);
	set("gender", "Ů��");
	set("age", 16);
	set("per",27);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	set("inquiry",([
		"tea":		(:give_tea:),
		"cha":		(:give_tea:),
		"������":	(:give_tea:),
		"��������":	(:give_tea:)]));

	setup();
	carry_object(__DIR__"obj/cuihongcloth")->wear();
}

int give_tea()
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_asktea(ob);
}
