inherit NPC;

void create()
{
        set_name("��������", ({"xiboer gu", "gu"}));
        set("long", "������ʯɽ�̲�̶���Ϲ꾫��\n");
        set("age", 30);
	set("title", "��ǰ��ʹ");
        set("attitude", "heroism");
	set("class", "yaomo");
        set("gender", "����");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",500);
        set("max_sen", 500);
        set("combat_exp", 50000);
  set("daoxing", 10000);

        set("eff_dx", -20000);
        set("nkgain", 250);

        set("force", 200);
        set("max_force", 200);
        set("mana", 200);
        set("max_mana", 200);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 40);
        set_skill("force", 40);
        set_skill("spells", 40);
        set_skill("dodge", 40);
	set_skill("fork", 40);
	set_skill("yueya-chan", 40);
	map_skill("fork", "yueya-chan");
	map_skill("parry", "yueya-chan");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

�