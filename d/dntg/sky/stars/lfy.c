//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("�˷���",({"star lfy","lfy","star"}));
  set("gender", "����");
  set("title", "�����ǹ�");
  set("age", 41);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 2473945);
  set("daoxing", 2473945);
  set("kee", 1258);
  set("max_kee", 1258);
  set("sen", 2223);
  set("max_sen", 2223);
  set("force", 5681);
  set("max_force", 2841);
  set("mana", 8479);
  set("max_mana", 4240);
  set("force_factor", 144);
  set("mana_factor", 213);
  set("str", 30);
  set("per", 10);


  set_skill("baguazhou", 11);
  set_skill("blade", 201);
  set_skill("buddhism", 41);
  set_skill("dodge", 154);
  set_skill("force", 197);
  set_skill("hellfire-whip", 86);
  set_skill("huntian-qigong", 191);
  set_skill("huoyun-qiang", 143);
  set_skill("kugu-blade", 277);
  set_skill("lingfu-steps", 220);
  set_skill("literate", 141);
  set_skill("ningxie-force", 22);
  set_skill("parry", 270);
  set_skill("spear", 61);
  set_skill("spells", 230);
  set_skill("sword", 65);
  set_skill("unarmed", 170);
  set_skill("whip", 64);
  set_skill("xiaoyaoyou", 47);
  set_skill("yaofa", 229);
  set_skill("yinfeng-zhua", 184);
  set_skill("zhuihun-sword", 42);


map_skill("force", "huntian-qigong");
map_skill("spells", "yaofa");
map_skill("dodge", "lingfu-steps");
map_skill("parry", "kugu-blade");
map_skill("unarmed", "yinfeng-zhua");
map_skill("blade", "kugu-blade");
  set("inquiry", ([
     "here" : "�������ǣ������ң�����˭ȥ����֪������֪��",
     "name" : "�˷��ƾ��Ǵ�ү�ң��Ҿ����˷��ơ�",
     "lfy" : "�˷��ƾ��Ǵ�ү�ң��Ҿ����˷��ơ�",
     "pk" : "��֪������pk�𣿿�ȥ���ҵ�pk����ɣ��ؼ�100�ƽ�һ����",
     "star" : "�ԣ����վ����ҵ����࣬�����ɣ��ٺ٣�",
     "����" : "�ԣ����վ����ҵ����࣬�����ɣ��ٺ٣�",
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"Ѫ"+HIC"��"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",YEL"�ȹ�"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",YEL"ͷ��"NOR);
}

