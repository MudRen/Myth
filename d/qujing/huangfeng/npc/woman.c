// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/woman.c

inherit NPC;

void create()
{
       set_name("������", ({"wang nainai", "wang", "nainai"}));
       set("long","���峤�����ţ�������׵����ˡ���æ���������\n");
       set("gender", "Ů��");
       set("age", 50);
       set("per", 100);
	set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 7400);
       set_skill("unarmed", 10);
	set_skill("dodge", 50);
	set_skill("parry", 20);
	setup();
       add_money("gold", 1);
       carry_object("/d/gao/obj/ao")->wear();

}
