//puti.c
inherit NPC;

void create()
{
       set_name("Ұ��", ({"ye gui", "gui"}));
       set("gender", "����");
       set("age", 20+random(20));
	set("long", "�������׶�֮������Ŀ������\n");
       set("attitude", "aggressive");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 7000+random(1000));
	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("blade", 20);


setup();

//        carry_object("/d/diyu/obj/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/gao/obj/blade")->wield();
}


