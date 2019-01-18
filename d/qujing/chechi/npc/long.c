// by snowcat oct 24 1997

inherit NPC;

string *names = ({
  "����ү",
  "����ү",
  "С��ү",
  "��Ʀ��",
  "СƦ��",
  "С����",
  "����",
  "������",
  "�ٹ���",
  "������",
  "�˹���",
  "����",
  "����",
});

string *ids = ({
  "da shaoye",
  "er shaoye",
  "xiao shaoye",
  "da pizi",
  "xiao pizi",
  "xiao guanren",
  "da gongzi",
  "er gongzi",
  "shao gongzi",
  "hua gongzi",
  "lang gongzi",
  "gongzi",
  "wang sun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "����");
  set("combat_exp", 5000+random(15000));
  set("age", 20+random(9));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",300);
  set("max_mana",300);
  set_skill("unarmed", 10+random(90));
  set_skill("unarmed", 10+random(90));
  set_skill("unarmed", 10+random(90));
  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", random(5));
}
