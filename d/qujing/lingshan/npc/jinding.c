//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;

void create()
{
  set_name("�𶥴���", ({ "jinding daxian", "jinding", "daxian" }));
  set("title", "��ɽ");
  set("gender", "����");
  set("age", 100);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 80);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 80);
  set("combat_exp", 1000000);
  set("daoxing", 1500000);

  set_skill("spells", 120);
  set_skill("dao", 120);
  set_skill("liangyi-sword", 120);
  set_skill("sword", 120);
  set_skill("unarmed", 120);
  set_skill("puti-zhi", 120);
  set_skill("dodge", 120);
  set_skill("jindouyun", 120);
  set_skill("parry", 120);
  set_skill("force", 120);
  set_skill("wuxiangforce", 120);
  set_skill("staff", 120);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindou-yun");
  map_skill("force", "wuxiangforce");
  map_skill("sword", "lingyi-sword");

  setup();
  carry_object("/d/obj/weapon/sword/changjian")->wield();
  carry_object("/d/obj/cloth/daopao")->wear();
}

�
