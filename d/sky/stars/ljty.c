
//note: this is created from player data.
inherit NPC;

void create()
{
	set_name("�˼�����", ({"ljty"}));
	set("long", @LONG
��ѩ���� --- ������������
    ����׷׷��д���������������
��
ϵ       ��ѩ������ַ
��   http://128.205.200.100/~xou
ѩ
��
    ѩԭççѩ��������ѩԭӳ����

LONG);
	set("title", "�����ǹ�");
	set("gender", "����");
	set("age", 57);
	set("class", "taoist");
	set("attitude", "friendly");
	set("per",27);
	set("max_kee", 892);
	set("max_gin", 200);
	set("max_sen", 1216);
	set("force", 2624);
	set("max_force", 1312);
	set("force_factor", 100);
	set("mana", 4006);
	set("max_mana", 2003);
	set("mana_factor", 79);
	set("combat_exp", 1107676);
	set("env/no_teach", 1);

	set("eff_dx", 800000);
	set("nkgain", 800);

	set_skill("blade", 1);
	set_skill("dao", 134);
	set_skill("dodge", 129);
	set_skill("force", 145);
	set_skill("hammer", 2);
	set_skill("jindouyun", 8);
	set_skill("kusang-bang", 5);
	set_skill("literate", 138);
	set_skill("parry", 170);
	set_skill("qianjun-bang", 147);
	set_skill("spells", 147);
	set_skill("stick", 150);
	set_skill("sword", 28);
	set_skill("tonsillit", 11);
	set_skill("unarmed", 36);
  	set_skill("whip", 0);
	set_skill("wuxiangforce", 128);

	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "moondance");

	create_family("����ɽ���Ƕ�", 2, "����");
	setup();

	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/stick/bintiegun")->wield();
}


