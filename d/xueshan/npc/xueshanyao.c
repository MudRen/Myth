// xunshi.c

inherit NPC;
void create()
{
	set_name("ѩɽ��", ({"xushan yao", "yao"}));
	set("gender", "����" );
	set("age", 33);
	set("long", "ѩɽ�����кܶ�Ѳʹ����Ϊ���˺����ܵ����\n�ڹ��ڵ�Ѳʹ����书���ߣ����ڴ�ѩɽ�ķ���������ϲ��ᡣ\n��λѲʹ�������ۣ������䵶�����۵�������һֻ�������ѵĴ�����\n�䵶��������Ө͸�����������Ժ����Ƴɡ�\n");
	set("class", "yaomo");
	set("combat_exp", 35000);
        set("daoxing", 30000);

        set("attitude", "aggressive");
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


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  ob = new (__DIR__"jing");
  ob->move(where);
  message_vision ("\n$Nһ����Х������ԭ�Σ�ԭ����ֻ$n��\n",me,ob);
  destruct (me);
}

void die ()
{
  unconcious();  
}

