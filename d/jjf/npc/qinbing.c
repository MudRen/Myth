// qinbing.c
// created 6-4-97 pickle

inherit NPC;

void create()
{
  set_name("�ױ�", ({ "qin bing", "qin", "bing", "qinbing"}));
  set("gender", "����");
  set("age", 19+random(30));
  set("title", "������");
  set ("long", @LONG
��Щ�ױ�������ɳ�����������������͵�ǿ����
���ǲ�ԭ�ܷ�Ϊ�٣����ϸ��汣��������
LONG);

  set("combat_exp", 160000+random(40000));
  set_skill("blade", 79);
  set_skill("force", 50);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("wuhu-blade", 100);
  set_skill("lengquan-force", 50);
  set_skill("unarmed", 80);
  //map_skill("force", "lengquan-force");
  map_skill("parry", "wuhu-blade");
  set("max_sen", 200);
  set("max_kee", 500+random(200));
  set("force", 400);
  set("max_force", 350);
  set("force_factor", 15);

  create_family("������", 3, "��");
  setup();

  carry_object("/d/obj/weapon/blade/kandao")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();

  setup();
}
	


