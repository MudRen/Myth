// xunshi.c

inherit NPC;
void create()
{
	set_name("����Ѳʹ", ({"xunshi", "shi"}));
	set("gender", "����" );
	set("age", 33);
	set("long", "��λѲʹ����ңԶ�Ĵ�ѩɽ�����������ۣ������䵶��\n���۵�������һֻ�������ѵĴ������䵶��������Ө͸�����������Ժ����Ƴɡ�\n");
	set("class", "yaomo");
	set("combat_exp", 50000);
  set("daoxing", 30000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 4, "����");
	set_skill("unarmed", 40);
	set_skill("yingzhaogong", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("bingpo-blade", 50);
	set_skill("xiaoyaoyou", 50);
	set_skill("spells", 40);
	set_skill("dengxian-dafa", 40);
	set_skill("force", 40);   
	set_skill("ningxie-force", 40);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "yingzhaogong");

	set("per", 19);
	set("max_kee", 400);
	set("max_sen", 400);
	set("force", 350);
	set("max_force", 300);
	set("mana", 400);
	set("max_mana", 350);
	set("force_factor", 30);
	set("mana_factor", 17);

	set("eff_dx", -15000);
	set("nkgain", 80);

	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

�