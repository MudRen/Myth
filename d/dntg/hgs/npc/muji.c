inherit NPC;

void create()
{
        set_name("��ĸ��", ({ "old hen", "hen" }) );
        set("race", "Ұ��");
	set("gender", "����");
        set("age", 5);
	set("long", "һֻ���ֵ���ĸ����\n");
        set("attitude", "friendly");
	set("str", 5);
	set("con", 20);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite"}) );

	set_skill("dodge", 20);
        set_temp("apply/armor", 1);

        setup();
}

