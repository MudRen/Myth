
inherit NPC;
void create()
{

  set_name("����ԣ", ({ "kang anyu", "kang", "taiwei" }) );
  set("gender", "����" );
  set("long", "����ԣ��÷ɽ���ֵ��е����ġ�\n");
  set("title", "÷ɽ̫ξ");
  set("age", 35);
  set("attitude", "peaceful");
  set("str", 25);
  set("int", 25);
  set("combat_exp",560000);
  set("force",800);
  set("max_force",800);
  set("force_factor", 20);
  set("max_kee", 900);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",109);
  set_skill("dodge",90);
  set_skill("parry", 90);
  set_skill("spear",90);
  set_skill("force",90);
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

�
