// linggui.c ���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"���"NOR, ({"ling gui", "ling"}));
       set("long", "��Цŭ��������棬ɱ����ָ��֮�䡣\n");
       set("title", HIC"������"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 42);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 400);
       set("max_force", 400);
       set("force_factor", 20);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("throwing", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "������˧���¾Ŵ����֮һ��\n",
	"here"     : "��������������\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/dujili")->wield();
}

�
