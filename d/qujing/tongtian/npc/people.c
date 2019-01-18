// by snowcat  11/22/1997

inherit NPC;

string *mnames = ({
  "�¿�",
  "��»",
  "����",
  "���",
  "����",
  "����",
  "���",
  "����",
  "�����",
  "������",
  "�´�ͷ",
  "��С��",
  "���ϴ�",
  "���϶�",
  "������",
  "������",
  "�´�",
  "�´���",
  "�´��",
  "�´��",
  "�´�ү",
  "�¶���",
  "�¶���",
  "�¶���",
  "�¶���",
  "�¶�ү",
  "������",
  "������",
  "������",
  "������",
  "����ү",
  "���Ĳ�",
  "������",
  "���ľ�",
  "���ĸ�",
  "����ү",
});

string *fnames = ({
  "����",
  "����",
  "����",
  "����",
  "��ɩ",
  "����",
  "�´���",
  "�´���",
  "�´���",
  "�´�ɩ",
  "�´���",
  "�¶���",
  "�¶���",
  "�¶���",
  "�¶�ɩ",
  "�¶���",
  "������",
  "������",
  "������",
  "����ɩ",
  "������",
  "������",
  "������",
  "������",
  "����ɩ",
  "������",
});

void create()
{
  string cloth;

  if (random(2))
  {
    int i = random(sizeof(mnames));
    set_name(mnames[i], ({"chen"}));
    set("gender", "����");
    cloth = "/d/qujing/tongtian/obj/cloth";
  }
  else
  {
    int i = random(sizeof(fnames));
    set_name(fnames[i], ({"chen"}));
    set("gender", "Ů��");
    cloth = "/d/qujing/tongtian/obj/skirt";
  }
  set("combat_exp", 1000+random(20000));
  set("age", 40+random(20));
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
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  setup();
  carry_object(cloth)->wear();
}


