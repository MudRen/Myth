inherit NPC;

void create()
{
        set_name("������", ({ "rat" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�ʷʵĴ�����\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 40);
        set("combat_exp", 20);

        setup();
}


