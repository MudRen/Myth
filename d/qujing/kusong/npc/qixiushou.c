//Cracked by Roath
inherit NPC;

void create()
{
        set_name("������", ({ "qixiu shou", "shou" }) );
        set("race", "Ұ��");
        set("age", 50);
        set("long", "һֻ������������������ͻ���һ˫�۾�����ݺݵص����㡣\n");
        set("attitude", "aggressive");
        set("bellicosity", 8000);
        set("str", 30);
        set("cor", 30);
 	set("per", 10);
        set("max_kee", 1500);
        set("max_sen", 1500);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 80);
	set("mana", 2000);
	set("max_mana", 1000);
	set("mana_factor", 80);

	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 800000);
  set("daoxing", 500000);


        set_temp("apply/damage", 50);
        set_temp("apply/armor", 100);

        setup();
}

�