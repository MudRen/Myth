//puti.c
inherit NPC;

void create()
{
       set_name("��ͷ��", ({"wutou gui", "gui"}));
       set("gender", "����");
	set("long", "һ��û��ͷ��ֻ�����ӵ�Ұ��\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 6000+random(1000));
	set_skill("unarmed",15);
	set_skill("dodge", 15);
	set_skill("parry", 35);


setup();

//        carry_object("/d/diyu/obj/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/diyu/obj/tielian")->wield();
}


