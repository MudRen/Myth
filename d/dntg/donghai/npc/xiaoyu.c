//sgzl

inherit NPC;

string *names = ({
  "С����",
  "С����",
  "С����",
  "С����",
  "С����",
});

string *ids = ({
  "xiao hong yu",
  "xiao qing yu",
  "xiao lan yu",
  "xiao bai yu",
  "xiao hua yu",
});

void create()
{
  int i;

  i=random(sizeof(names));
  set_name(names[i], ({ids[i], "xiao yu", "fish", "yu"}));
  set("long","һ��"+names[i]+"�����ں����������ڵ����š�\n");

  set("race", "Ұ��");
  set("age", 2);

  set_skill("dodge", 60);
  set("combat_exp", 10);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);
  set("chat_msg", ({
                names[i]+"���˰�β�͡�\n",
                (: random_move :)
        }) );

  setup();
}

