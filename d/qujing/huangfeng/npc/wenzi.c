//Cracked by Roath
inherit NPC;

string *names = ({
  "[31m��������[m",
  "��ͷ����",
  "��ͷ����",
  "��ͷ����",
  "��������",
  "��������",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ "wen zi","wenzi" }) );
   set("race", "Ұ��");
   set("age", 3);
   set("long", "һֻ��С�ɵĻ������ӡ�\n");

   set("str", 32);
   set("max_kee",200);
   set("kee",200);
   set("max_sen",200);
   set("sen",200);
   set("limbs", ({ "ͷ��", "����", "��", "���", "���" }) );
   set("verbs", ({ "bite", "claw" }) );
   set("chat_chance",80);
   set("chat_msg",({
        "���������˵ķ�����ȥ��\n",
        }));
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);
   setup();
}
