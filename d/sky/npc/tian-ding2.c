// tian-ding2.c
// created 4-8-97 pickle
#include <ansi.h>
inherit NPC;
string *first_name = ({ "�˹���","����Ȫ","��ѧ��","��꿸�"});
// �ӣ����������ϣ��ˣ������ţ���

varargs void drool(string msg, string who);

void create()
{
  string name, id;

  name = first_name[random(sizeof(first_name))];

  set_name(name, ({ "tian ding", "tian", "ding" }) );
  set("gender", "����" );
  set("long", "

������Ĵ��ڣ�"+name+"�ƺ�˿��û��ע�⡣
ֱ�����߽����ţ����Ž���������Ŀ�⳯��ɨ��һɨ��
");
  set("title", "�����춡");
  set("attitude", "peaceful");
  set("age", 35+random(10));
  set("str", 27);
  set("int", 25);
  set("combat_exp",380000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 20);
  set("max_kee", 850);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",99);
  set_skill("dodge",99);
  set_skill("parry",99);
  set_skill("axe",99);
  set_skill("force",80);
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/axe/bigaxe")->wield();
}
�