// cglaem.c
inherit NPC;

void create()
{
        set_name("С��", ({ "wolf" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�����������С�ǣ�һ˫�۾�����ݺݵص����㡣\n");
        set("attitude", "friendly");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);

        set_temp("apply/armor", 5);

        setup();
}

