inherit NPC;

void create()
{
        set_name("Ұ����", ({ "rat" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�ʷʵĴ����󡣵���һ˫С�۾������������ת����֪����ʲô\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 50);
	set("combat_exp", 1000);

        setup();
}

