//sgzl

inherit NPC;

void create()
{
  set_name("��ʿ",({"dao shi","dao","shi"}));
  set("gender", "����");
  set("age", 55);
  set("long", "    \n���ʹ��￴�ذ���¯�ĵ�ʿ��\n");

  set("attitude", "peaceful");
  set("class", "taoist");
  set("combat_exp", 20000);
  set("daoxing", 40000);
  set("kee", 400);
  set("max_kee", 400);
  set("sen", 400);
  set("max_sen", 400);
  set("force", 400);
  set("max_force", 400);
  set("mana", 400);
  set("max_mana", 400);
  set("force_factor", 5);
  set("mana_factor", 10);


  set_skill("spells", 30);
  set_skill("dao", 30);
  set_skill("dodge", 60);
  set_skill("parry", 40);
  set_skill("unarmed", 30);


  set("inquiry", ([
  "here"   : "������Ƕ��ʹ������������ʲô��",
]));


setup();

carry_object("/d/lingtai/obj/cloth")->wear();

}
