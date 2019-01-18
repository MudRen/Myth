// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/huxianfeng.c

inherit NPC;
void create()
{
	set_name("���ȷ�", ({"hu xianfeng", "hu", "xianfeng"}));
	set("gender", "����" );
	set("age", 43);
	set("per", 112);//no rongmao description.
	set("str", 50);
	set("long", "�Ʒ�������µ�ǰ·�ȷ棬�ǻƷ��������������֡�\n���ո�ǿ�����¸ɾ����䣬����������ƨ��\n������Ʒ�ɽ������һ��֮������֮�ϡ�\n");
	set("class", "yaomo");
	set("combat_exp", 800000);
	set("attitude", "peaceful");
	set_skill("unarmed", 130);
	set_skill("cuixin-zhang", 70);
	set_skill("dodge", 60);
	set_skill("xiaoyaoyou", 70);
	set_skill("parry", 120);
	set_skill("force", 90);   
	set_skill("ningxie-force", 80);
	set_skill("literate", 70);
	set_skill("spells", 90);
	set_skill("dengxian-dafa", 80);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill ("parry","cuixin-zhang");

	set("max_kee", 1200);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 800);
	set("max_mana", 400);	
	set("force_factor", 60);
	set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

	setup();
	carry_object("/d/qujing/huangfeng/obj/hupi")->wear();
}
void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/huangfeng/obj/hupi");

  message_vision ("$N�ҽ����з����أ����̹�����ֻ����һ���ϻ�Ƥ��\n",me);
  ob->move(where);
  destruct(me);
}
