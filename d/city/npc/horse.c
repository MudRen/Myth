/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

string *names = ({
  "ǧ����",
  "�ɺ���",
  "�����",
  "����",
  "����",
  "����",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"horse", "ma"}));
  set("race", "Ұ��");
  set("age", 10);

  set_skill("dodge", 60);
  set("combat_exp", 10000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "��");
  set("ride/dodge", 10+random(6));
  set_temp("apply/attack", 10);
  set_temp("apply/armor", 20);

  setup();
}

