//Cracked by Roath
// tidu.c

#include <ansi.h>

inherit NPC;

string ask_for_join();
string ask_for_leave();
string ask_for_huansu();

void create()
{
	set_name("���ɮ", ({ "tidu seng", "seng" }) );

	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 200);
	set("max_atman", 200);

	set("force", 150);
	set("max_force", 150);
	set("force_factor", 5);

	set("mana", 200);
	set("max_mana", 200);

	set("combat_exp", 10000);
	set("daoxing", 50000);

	set("inquiry", ([
		"���" : (: ask_for_join :),
		"����" : (: ask_for_join :),
		"����" : (: ask_for_huansu :),
		"����" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
		]) );

	set_skill("staff", 20);
	set_skill("unarmed", 30);
	set_skill("force", 25);
	set_skill("dodge", 20);
	set_skill("literate", 20);
	set_skill("parry", 20);
	set_skill("spells", 10);

	set_skill("lotusforce", 20);
	set_skill("buddhism", 20);

	map_skill("force", "lotusforce");
	map_skill("spells", "buddhism");

	create_family("�Ϻ�����ɽ", 4, "����");

	setup();

	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
        add_action("do_agree", "agree");
        add_action("do_huansu", "huansu");
}

string ask_for_huansu()
{
	object me;

	me = this_player();

	if( (string)me->query("bonze/class")!="bonze" )
		return "�����ӷ��������ϵ�������αش�������֣�\n";
	me->set_temp("pending/leave_bonze", 1);
command("say �����ӷ�һ����������ٲ�����"+RANK_D->query_respect(me)+"һ���˷�Ҳ����֮�����������"+RANK_D->query_respect(me)+"��˼��");
	return RANK_D->query_respect(me)+"���Ѿ������������ۻ���(huansu)��\n";
}

int do_huansu()
{
        if( !this_player()->query_temp("pending/leave_bonze") ) return 0;
	message_vision( HIC "$N�������ϵ����ģ����������ع��������˼�����ͷ���Ӵ˻ָ���������\n\n"NOR, this_player(), this_object() );
	this_player()->delete("class");
	this_player()->delete("bonze/class");
	this_player()->delete_skill("buddhism");
	command("say �ӽ�������ָ�����ǰ������" +this_player()->query("bonze/old_name")+"��");
	this_player()->set("name", this_player()->query("bonze/old_name") );
	command("sigh");
        this_player()->delete_temp("pending/leave_bonze");
	this_player()->save();
	return 1;
}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("married"))
		return "�����ӷ�ʩ�����˼�ͥ���ۣ��������Ǳ�����\n";
	if( (string)me->query("bonze/class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��\n";
	if( me->query("bonze/justonetime"))
		return "ʩ�����ѻ��ף��ֺο��ٴγ��ң�\n";
	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	string *prename1 =
         ({ "��", "��", "��", "��", "��", "��" });
	string *prename2 =
         ({ "��", "��", "��", "��", "��", "��" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(	HIC "$N˫�ֺ�ʮ�����������ع���������\n\n" + 
			"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n" NOR,
		this_player(), this_object() );
	name = this_player()->query("name");
	new_name = ( (string)this_player()->query("gender") == "����" )? 
		prename1[random(sizeof(prename1))] + name[0..1]
		:prename2[random(sizeof(prename2))] + name[0..1];
	command("say �ӽ�������ķ�������" + new_name + "��");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("bonze/class", "bonze");
	this_player()->set("bonze/justonetime", 1);
	this_player()->set("bonze/old_name", name);
        this_player()->set("class", "bonze");
	this_player()->save();
	return 1;
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "�Ϻ�����ɽ" ) {
                command("say �����ִ����ɽ��ƶɮȴ�м��仰˵�����Ų��ݾ�ѧ�����������书�ҽ��ջء�");
                me->set_temp("pt_betray", 2);
		return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)?\n");
	}

	return ("ƶɮ��֪��\n");
}
			
			
int do_agree(string arg)
{
        if(this_player()->query_temp("pt_betray") > 1 &&
		this_player()->query("family/family_name") == "�Ϻ�����ɽ") {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		this_player()->add("betray/putuo", 1);
		this_player()->add("betray/count", 1);
		command("say �������������Ե�������ɽȥ�ɣ�\n");

                this_player()->add("combat_exp", -(this_player()->query("combat_exp")/5));
                this_player()->delete_temp("pt_betray");
                this_player()->add("daoxing", -(this_player()->query("daoxing")/5));

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete_skill("buddhism");
                this_player()->delete_skill("lunhui-zhang");
                this_player()->delete_skill("huoyun-qiang");
                this_player()->delete_skill("lotusforce");
                this_player()->delete_skill("lotusmove");
                this_player()->delete_skill("jienan-zhi");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("betray", 0);
		command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
		this_player()->save();
		return 1;
	}

}
�
