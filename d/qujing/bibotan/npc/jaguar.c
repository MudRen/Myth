inherit NPC;

void create()
{
        set_name("���߱�", ({ "jaguar" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ���ߴ󱪣�һ˫�۾�����ݺݵص����㡣\n");
	set("looking", "�������������ݡ�");
        set("attitude", "aggressive");
        set("bellicosity", 20000);
        set("str", 50);
        set("cor", 30);
        set("max_kee", 1000);
        set("max_sen", 500);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 50);

        setup();
}
