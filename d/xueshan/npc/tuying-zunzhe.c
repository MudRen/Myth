// tuying-zunzhe.c...weiqi, 97.09.15.

#include <ansi.h>

inherit NPC;
string expell_me(object me);
void create()
{
	set_name("ͺӥ����", ({"tuying zunzhe", "tuying", "zunzhe"}));
	set("title", "��������");
	set("gender", "����" );
	set("age", 53);
	set("per", 112);//no rongmao description.

	set("long", "�������������Ļ�������֮һ����ͷ���ʣ�һ����֪���������\n");
	set("class", "yaomo");
	set("combat_exp", 500000);
	set("daoxing", 400000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 2, "����");
	set_skill("unarmed", 80);
	set_skill("yingzhaogong", 150);
	set_skill("dodge", 120);
	set_skill("xiaoyaoyou", 120);
	set_skill("parry", 70);
	set_skill("blade", 70);
	set_skill("bingpo-blade", 70);
	set_skill("force", 90);   
	set_skill("ningxie-force", 90);
	set_skill("literate", 60);
	set_skill("spells", 90);
	set_skill("dengxian-dafa", 100);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "yingzhaogong");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	set("max_kee", 800);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1000);
	set("max_mana", 500);	
	set("force_factor", 50);
	set("mana_factor", 25);

        set("eff_dx", -120000);
        set("nkgain", 300);

	set("inquiry", ([
		"leave": (: expell_me :),
		"name": "�ٺ٣�\n",
		"here": "�࿴��˵��\n",
	]) );


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	//carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="��ѩɽ" ){
		if( (int)ob->query("family/generation") < 2  ){
			command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
		}
		else if( (int)ob->query("family/generation") ==2  ){
			command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ү���ˣ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command(":D");
			command("say �����" + RANK_D->query_rude(ob) + "��͸�������Ϊʦ�����Ǹ���ʦ��ʲô������...\n");
			command("recruit " + ob->query("id") );
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 150000 ){
				command(":D ");
				command("say �ã�����������ѧ�գ���Ĳ�˵����֤" + RANK_D->query_respect(ob) + "��һ˫�����������ѻ�����\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say �㻹�������ģ���ѻ���������Űɡ�\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ��λ" + RANK_D->query_respect(ob) + "��û���Ƽ����ҿɲ������㡣\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

string expell_me(object me)
{       
	int stage, bonus;
	me=this_player();

	stage=(int)me->query("nx-force_bonus");
	if( stage < 2 ) bonus = 0;
	else if( stage == 2 ) bonus = 100;
	else if( stage == 3 ) bonus = (2+3)*50;
	else if( stage == 4 ) bonus = (2+3+4)*50;
	else if( stage == 5 ) bonus = (2+3+4+5)*50;
	else if( stage == 6 ) bonus = (2+3+4+5+6)*50;
	else if( stage == 7 ) bonus = (2+3+4+5+6+7)*50;
	else if( stage == 8 ) bonus = (2+3+4+5+6+7+8)*50;
	else                  bonus = (2+3+4+5+6+7+8+9)*50;


	if((string)me->query("family/family_name")=="��ѩɽ") {
		message_vision("ͺӥ������ɫһ���������������Ǳ���Σ��֮ʱ...\n", me);
		me->set_temp("xs_betray", 2);
		message_vision("ͺӥ������ɭɭ�ض���$N�����ŵ������������(true)��\n", me);
		if ( bonus> 0 )
		{
                        message_vision("ͺӥ���߶���һ�£����У����ڱ��ŵõ��ô��ɱ�����ߣ���������"+chinese_number(bonus)+"������������书��\n", me);
			me->set_temp("xs_neili_penalty", bonus);
		}
		return ("�ٺ٣�\n");
	}
	return ("��ʲô�ʣ��Լ���ȥ��\n");
}

void init()
{
	add_action("do_true", "true");
}

int do_true(string arg)
{
	if(this_player()->query_temp("xs_betray") > 1 ) {
		message_vision("$N��������ӽ������Ļ���\n\n", this_player());
		message_vision("ͺӥ����̾�˿��������ã���Ӵ˱��Ǳ��ŵĵ����ˣ�\n", this_player());
		this_player()->add("betray/xueshan", 1);
		this_player()->add("betray/count", 1);

                this_player()->add("combat_exp", -(this_player()->query("combat_exp")/5));
                this_player()->add("daoxing", -(this_player()->query("daoxing")/5));
                this_player()->delete_skill("dengxian-dafa");
                this_player()->delete_skill("bainiao-jian");
                this_player()->delete_skill("cuixin-zhang");
                this_player()->delete_skill("throwing");
                this_player()->delete_skill("xiaoyaoyou");
                this_player()->delete_skill("yingzhaogong");
                this_player()->delete_skill("bingpo-blade");
		this_player()->delete_skill("ningxie-force");

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/xueshan", 1);
		this_player()->set("title", "��ͨ����");
		this_player()->delete_temp("xs_betray");

		this_player()->set("max_force", 
			(this_player()->query("max_force")  
			- this_player()->query_temp("xs_neili_penalty")) );

		this_player()->delete_temp("xs_neili_penalty");
		this_player()->save();
		message_vision("ͺӥ����һ������$N��ƨ�ɣ�$N���Ƽ������˳�ȥ...\n", this_player());
		this_player()->move("/d/xueshan/binggu");
		tell_room( environment(this_player()),"ֻ����ž��һ����һ���˴ӿ��зɹ�����������ˤ�ڵ��ϡ�\n", ({this_player()}));
		return 1;
	}
	return 0;
}

�
