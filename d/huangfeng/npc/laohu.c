// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/laohu.c

inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "lao hu","hu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ�������ݵ��ͻ���¶����ɭɭ�����ݶ�ݺݵص����㡣\n");
        set("attitude", "aggressive");
	  set("bellicosity", 20000);
        set("str", 20);
        set("cor", 30);
	  set("max_kee", 1300);
	  set("max_sen", 1200);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);

        set_temp("apply/damage", 15);
        set_temp("apply/armor", 20);
		set_skill("unarmed",100);
		set_skill("parry",100);
		set_skill("dodge",150);

        setup();
}


