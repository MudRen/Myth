// xunshi.c

inherit NPC;
void create()
{
	set_name("����Ѳʹ", ({"xunshi", "shi"}));
	set("gender", "����" );
	set("age", 33);
	set("long", "ѩɽ�����кܶ�Ѳʹ����Ϊ���˺����ܵ����\n�ڹ��ڵ�Ѳʹ����书���ߣ����ڴ�ѩɽ�ķ���������ϲ��ᡣ\n��λѲʹ�������ۣ������䵶�����۵�������һֻ�������ѵĴ�����\n�䵶��������Ө͸�����������Ժ����Ƴɡ�\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 20000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 4, "����");
	set_skill("unarmed", 30);
	set_skill("yingzhaogong", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("blade", 30);
	set_skill("bingpo-blade", 30);
	set_skill("xiaoyaoyou", 30);
	set_skill("force", 30);   
	set_skill("ningxie-force", 30);
	map_skill("force", "ningxie-force");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "yingzhaogong");

	set("per", 19);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);

	set("eff_dx", -8000);
	set("nkgain", 60);

	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

�