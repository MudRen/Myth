inherit NPC;

void create()
{
        set_name("��������ʿ", ({ "wu shi", "shi", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
	set("long", "���������س��ŵ���ʿ���������ݵ�Ѳ������Χ��\n");
        set("combat_exp", 75000);
  set("daoxing", 25000);

        set("attitude", "friendly");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);

        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 15);

        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/niupi")->wear();
}


�