//sgzl

inherit NPC;

void create()
{
set_name("ƫ��",({"pian jiang","jiang"}));
set("gender", "����");
set("title", "������");
set("age", 25);
set("long", "    \nһ����������ƫ�������������վ�ڡ�\n");

set("attitude", "heroism");
set("class", "fighter");
set("combat_exp", 25000);
  set("daoxing", 10000);

set("kee", 400);
set("max_kee", 400);
set("sen", 420);
set("max_sen", 420);
set("force", 350);
set("max_force", 350);
set("mana", 100);
set("max_mana", 100);
set("force_factor", 15);
set("mana_factor", 0);


set_skill("dodge", 50);
set_skill("spells", 30);
set_skill("unarmed", 50);
set_skill("parry", 50);
set_skill("spear", 30);


set("inquiry", ([
]));


setup();

carry_object("/d/obj/weapon/spear/tieqiang")->wield();
carry_object("/d/obj/cloth/bingfu")->wear();

}


void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N���������������ģ����˽ٱ�����������˵���������˳�ȥ��\n",me);
  message_vision ("\n��һ��$N����ææ�ĸ�����\n",me);
  ob = new (__DIR__"pianjiang");
  ob->move(where);
  destruct (me);
}

void die ()
{
  unconcious();  
}

�