inherit NPC;

void create()
{
        set_name("��ţ", ({"niu"}));
        set("race", "Ұ��");
        set("age", 15);
        set("long", "һͷ��ţ��\n");
        set("attitude", "friendly");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);

	set("ride/msg", "��");
  	set("ride/dodge", 10);
        set_temp("apply/armor", 20);

        setup();
}

