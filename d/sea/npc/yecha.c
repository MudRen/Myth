inherit NPC;

void create()
{
       	set_name("Ѳ��ҹ��", ({"ye cha", "yecha", "cha"}));
       	set("long","һ��Ѳ����ҹ�棬�������������\n");
       	set("gender", "����");
       	set("per", 10);
	set("str", 20);
       	set("max_kee",700);
	set("max_sen", 600);
       	set("attitude", "heroism");
       	set("combat_exp", 120000+random(30000));
  set("daoxing", 100000);

       	set_skill("parry", 80);
       	set_skill("dodge", 80);
	set_skill("unarmed", 80);
       	set_skill("fork", 80);
	set("force", 300);
	set("max_force", 300);
       	set("force_factor", 10);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 10);
	setup();
       	carry_object("/d/obj/armor/shoupi")->wear();
       	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}


�