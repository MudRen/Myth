//puti.c
inherit NPC;

void create()
{
       set_name("��˾��", ({"gousi ren", "ren"}));
       set("gender", "����");
       set("age", 30);
	set("long", "һЩ�ظ����������Ա��\n");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 20000+random(5000));
  set("daoxing", 30000);

	set("bellicosity", 100);
	set_skill("unarmed", 35);
	set_skill("dodge", 35);
	set_skill("parry", 45);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 5);
	set("max_kee", 450);
set("inquiry", ([
"here": "��������ܵظ���\n",
]) );

set("chat_chance", 8);
set("chat_msg", ({
(: random_move :)
}) );

setup();

        carry_object("/d/gao/obj/changpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/diyu/obj/tielian")->wield();
}


�