inherit NPC;

void create()
{
        set_name("�Ų�����", ({"guboer xi", "xi"}));
        set("long", "������ʯɽ�̲�̶���ϱ��\n");
        set("age", 30);
	set("title", "��ǰ��ʹ");
        set("attitude", "peaceful");
        set("gender", "����");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",500);
        set("max_sen", 500);
        set("combat_exp", 45000);
  set("daoxing", 60000);

        set("eff_dx", 20000);
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