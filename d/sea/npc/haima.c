inherit NPC;

void create()
{
        set_name("�𱳺���", ({"hai ma", "ma"}));
        set("race", "Ұ��");
        set("age", 25);
        set("long", "һֻ�𱳵Ĵ���������ү�����\n");
        set("attitude", "friendly");

     set("under_water",1);
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 10000);
  set("daoxing", 20000);


	set("ride/msg", "��");
  	set("ride/dodge", 15);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 20);

        setup();
}


�
