//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("���",({"star erica","erica","star"}));
  set("gender", "Ů��");
  set("title", "Σ���ǹ�");
  set("age", 47);
  set("long", "    \nһ�ж��Ƕ��ݵ�û�н���ȴ��Ҫ��ʼ��\nһ���ֶ���������û��ֹͣȴҲ������ɡ�\nΪ�˷�����������������Ҳ��ֻ��ʧȥ������ʧȥ��Ҳֻ�ܻӻ���˵���ټ�ȴ��\n�޾��׵�˲�䣬��㾭���̻��Ÿе�һ��ͻ�������ı�����\n�κε�·��ѡ��ֻ����ζ��ѡ��������·�Ĳ��ٿ��ܡ�\n���ս��¶���\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1335792);
  set("daoxing", 1335792);
  set("kee", 1185);
  set("max_kee", 1185);
  set("sen", 1869);
  set("max_sen", 1869);
  set("force", 5099);
  set("max_force", 2550);
  set("mana", 7099);
  set("max_mana", 3550);
  set("force_factor", 115);
  set("mana_factor", 178);
  set("str", 21);
  set("per", 22);


  set_skill("baihua-zhang", 17);
  set_skill("dodge", 144);
  set_skill("force", 101);
  set_skill("hammer", 47);
  set_skill("jueqingbian", 32);
  set_skill("literate", 140);
  set_skill("moondance", 201);
  set_skill("moonforce", 180);
  set_skill("moonshentong", 189);
  set_skill("ningxie-force", 21);
  set_skill("parry", 92);
  set_skill("snowsword", 209);
  set_skill("spells", 192);
  set_skill("sword", 200);
  set_skill("unarmed", 51);
  set_skill("whip", 97);
  set_skill("zhuihun-sword", 9);


map_skill("force", "moonforce");
map_skill("spells", "moonshentong");
map_skill("dodge", "moondance");
map_skill("parry", "snowsword");
map_skill("unarmed", "baihua-zhang");
map_skill("sword", "snowsword");
  set("inquiry", ([
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"��"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"��������"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"��������"NOR);
}

