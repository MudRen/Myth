// jiading.c �Ҷ�

inherit NPC;

void create()
{
  set_name("Сͯ", ({ "xiao tong", "xiaotong", "tong", "xiao"}));
  set("gender", "����");
  set("age", 7+random(8));
  set("long", "�ظ���Сͯ������С�ʹ�����书���ף��������¶��е㹦��\n");

  set("combat_exp", 4000);
  set_skill("dodge", 20);
  set_skill("unarmed", 20);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}
	
