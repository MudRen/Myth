//Cracked by Roath
// zhangchan.c ����ɮ
// By Dream Dec. 20, 1996

inherit NPC;

string ask_staff(object who);
string ask_spear(object who);

void create()
{
	set_name("����ɮ", ({ "zhangchan seng", "seng" }));
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 250);
	set("max_gin", 250);
	set("max_sen", 250);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 20);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 20);
	set("combat_exp", 10000);
	set("daoxing", 60000);

	set_skill("literate", 30);
	set_skill("spells", 10);
	set_skill("unarmed", 30);
	set_skill("jienan-zhi", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("force", 30);
	set_skill("staff", 30);
	map_skill("unarmed", "jienan-zhi");

	set("inquiry", ([
		"����": "����Ҫʲô������",
		"����": (: ask_staff :),
		"��ǹ": (: ask_spear :)
	]) );

	set("apply/staffno", 10);
	set("apply/spearno", 10);
        create_family("�Ϻ�����ɽ", 4, "����");
	
	setup();
//        carry_object("/obj/money/silver");
        add_money("silver", 20);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}


string ask_staff(object me)
{
	object ob, who = this_player();
	int number;


	if (who->query("family/family_name") != "�Ϻ�����ɽ") 
		return RANK_D->query_respect(who) +"�뱾�ź���ԨԴ��Ϊʲô���������\n";

	if (present("tie zhang", who)) return "�����ϲ����Ѿ�������������ô����Ҫ��\n";

	if (!(number = me->query("apply/staffno"))) return "�Բ��𣬱����Ѿ�ȫ�����ų�ȥ�ˡ�\n";
	set("apply/staffno", --number);

	ob = new("/d/nanhai/obj/tiezhang");
	ob -> move(me);
	command("give " + who->query("id") + " staff");
	return "ǧ���ס������ֻ����������������ɱ�޹���";
}

string ask_spear(object me)
{
        object ob, who = this_player();
        int number;

        if (who->query("family/family_name") != "�Ϻ�����ɽ")
		return RANK_D->query_respect(who) +"�뱾�ź���ԨԴ��Ϊʲô���������\n";

	if (present("iron spear", who)) return "�����ϲ����Ѿ�����ǹ������ô����Ҫ��\n";

	if (!(number = me->query("apply/spearno"))) return "�Բ��𣬱����Ѿ�ȫ�����ų�ȥ�ˡ�\n";
	set("apply/spearno", --number);

	ob = new("/d/nanhai/obj/tieqiang");
	ob -> move(me);
	command("give " + who->query("id") + " spear");
	return "ǧ���ס������ֻ����������������ɱ�޹���";
}

�
