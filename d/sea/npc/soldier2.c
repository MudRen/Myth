inherit NPC;

void create()
{
        set_name("з��", ({"xie jiang", "xie"}));
        set("long","һ�����ſ��׵Ĵ��з����������ȥά������\n");
        set("gender", "����");
        set("age", 20);
        set("per", 10);
        set("attitude", "heroism");
        set("combat_exp", 30000);
  set("daoxing", 30000);

        set_skill("parry", 35);
        set_skill("dodge", 35);
	set_skill("unarmed", 30);
	set_skill("fork", 30);
	set("max_kee", 350);
	set("max_sen", 350);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

�