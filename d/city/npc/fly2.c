//Creat by waiwai@2001/05/03

inherit NPC;

void create()
{
        set_name("��Ӭ", ({ "fly" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ��ͷ���Ĵ��Ӭ��\n");

        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 100);

        setup();
}

