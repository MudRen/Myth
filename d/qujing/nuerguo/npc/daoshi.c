// daoshi.c

inherit NPC;

void create()
{
  set_name("��ʿ", ({"daoshi"}));
  set("gender", "����" );
  set("age", 43);
  set("long", "�����������ɹ̫�����������Գ�һ�����������ӡ�\n");
  set("class","taoist");
  set("combat_exp", 10000);
  set("daoxing", 20000);

  set("attitude", "peaceful");
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set("per", 15);
  set("max_kee", 300);
  set("max_gin", 200);
  set("max_sen", 300);
  set("force", 100);
  set("max_force", 100);
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

�