//Cracked by Roath
// zhangchu.c �Ƴ�ɮ�
// By Dream Dec. 20, 1996

inherit NPC;

string *have_yao=({});
string *have_dan=({});

string ask_yao(object who);
string ask_dan(object who);

void create()
{
	set_name("�Ƴ�ɮ", ({ "zhangchu seng", "seng" }));
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);
	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

	set("inquiry", ([
		"���ϰ�ҩ": (: ask_yao :),
		"�鵤": (: ask_dan :),
	]) );
        set("apply/yaono", 10);
        set("apply/danno", 10);

        create_family("�Ϻ�����ɽ", 4, "����");
	
	setup();
        add_money("silver", 10);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

string ask_yao(object me)
{
	object ob, who = this_player();
	int number;

        if (who->query("family/family_name") != "�Ϻ�����ɽ") 
		return RANK_D->query_respect(who) +"�뱾�ź���ԨԴ��Ϊʲô���������\n";

if (present("yunnan baiyao", who)) return "�����ϲ����Ѿ������ϰ�ҩ������ô����Ҫ��\n";
	
	if (!(number = me->query("apply/yaono"))) return "�Բ������ϰ�ҩ�Ѿ�ȫ�����ų�ȥ�ˡ�\n";
	
	if(member_array(who->query("id"),have_yao)!=-1)
	    return "�㲻�Ǹո�Ҫ����\n";
	have_yao+=({who->query("id")});

	set("apply/yaono", --number);

	ob = new("/d/ourhome/obj/yunnandrug");
	ob -> move(me);
	command("give " + who->query("id") + " yunnan baiyao");
	return "���ϰ�ҩ��֮���ף�Ҫ��Լ���á�\n";
}

string ask_dan(object me)
{
	object ob, who = this_player();
	int number;

	if (who->query("family/family_name") != "�Ϻ�����ɽ")
		return RANK_D->query_respect(who) +"�뱾�ź���ԨԴ��Ϊʲô���������\n";

	if (present("lingdan", who)) return "�����ϲ����Ѿ����鵤������ô����Ҫ��\n";

	if (!(number = me->query("apply/danno"))) return "�Բ����鵤�Ѿ�ȫ�����ų�ȥ�ˡ�\n";

	if(member_array(who->query("id"),have_dan)!=-1)
	    return "�㲻�Ǹո�Ҫ����\n";
	have_dan+=({who->query("id")});

	set("apply/danno", --number);

	ob = new("/d/nanhai/obj/lingdan");
	ob -> move(me);
	command("give " + who->query("id") + " lingdan");
	return "�鵤��֮���ף�Ҫ��Լ���á�\n";
}

