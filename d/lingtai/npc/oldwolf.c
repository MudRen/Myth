// cglaem.c
inherit NPC;

void create()
{
        set_name("����", ({ "wolf" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ��������������ǣ�һ˫�۾�����ݺݵص����㡣\n");
        set("attitude", "aggressive");
	set("bellicosity", 20000);
        set("str", 20);
        set("cor", 30);
	set("max_kee", 300);
	set("max_sen", 200);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 10000);

        set_temp("apply/damage", 5);
        set_temp("apply/armor", 10);

        setup();
}

