//Cracked by Roath
inherit NPC;

void create()
{
        set_name("��Գ", ({ "bai yuan", "yuan" }) );
        set("race", "Ұ��");
        set("age", 80);
        set("long", "һֻ�����Ŵ�����ë����Գ��\n");

        set("str", 30);
        set("dex", 30);
	set("int", 30);
	set("con", 30);
	set("cor", 50);
	set("spi", 50);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 999000);
  set("daoxing", 1200000);

	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("sword", 170);
	set_skill("xiaofeng-sword", 170);
	set_skill("parry", 170);
	set_skill("dodge", 150);
	set_skill("moshenbu", 150);
	set_skill("force", 150);
	set_skill("spells", 150);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "xiaofeng-sword");
	map_skill("sword", "xiaofeng-sword");
	map_skill("unarmed", "changquan");

	set("max_kee", 1600);
	set("max_sen", 1600);
	set("mana", 2000);
	set("max_mana", 1000);
	set("mana_factor", 60);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 120);

        set_temp("apply/attack", 20);
        set_temp("apply/armor", 50);

        setup();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

�