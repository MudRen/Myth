// created 4/4/1997 by snowcat

inherit NPC;

void create()
{
  set_name("÷ԧ��", ({"mei yuanyan", "mei"}));
  set("title", "����Ůʹ");
  set("gender", "Ů��");
  set("age", 42);
  set("long", "һλ�������������Ůʹ����\n");
  set("combat_exp", 30000);
  set_skill("snowsword", 40);
  set_skill("sword", 40);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("dragonstep", 30);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force", 400);
  set("max_force", 200);
  set("force_factor", 4);

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  carry_object("/d/obj/weapon/sword/xijian")->wield();
}

void init()
{
  ::init();
}

