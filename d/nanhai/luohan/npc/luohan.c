//Cracked by Roath
inherit NPC;

string *first_name = ({ "����",
			"����",
			"�徲",
			"����",
			"����",
			"���",
			"����",
			"����",
			"�̴",
			"����",
			"����",
			"ׯ��",
			"�ǻ�",
			"����",
			"����",
			"����",
			"����",
			"����"
});

string *name_words = ({"�޺�"});

int create()
{
	string name;
	name = first_name[ID];
	name+= name_words[random(sizeof(name_words))];

	set_name(name, ({"luo han", "luohan"}));
  	set("long", "�Ϻ���������ʮ���޺���\n");
	set("title", "ʮ���޺�");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "ƶɮ");
        set("class", "bonze");
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        set("force", 3600);
        set("max_force", 1800);
        set("force_factor", 50);
        set("max_mana", 2000);
        set("mana", 4000);
        set("mana_factor", 50);

	set("daoxing", 2000000);
	set("combat_exp", 2000000);

        set("eff_dx", 720000);
        set("nkgain", 500);

        set_skill("spells", 150);
        set_skill("buddhism", 150);
        set_skill("unarmed", 150);
        set_skill("jienan-zhi", 150);
        set_skill("dodge", 150);
        set_skill("lotusmove", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("lotusforce", 150);
        set_skill("staff", 150);
        set_skill("lunhui-zhang", 150);

        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("staff", "lunhui-zhang");
/*
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
                (: cast_spell, "jingang" :),
		(: perform_action, "staff", "diyu" :),
        }) );
*/
        create_family("�Ϻ�����ɽ", 2, "����");

        setup();
        carry_object("/d/nanhai/obj/sengpao")->wear();
        carry_object("/d/nanhai/obj/budd_staff")->wield();
        return 1;
}
