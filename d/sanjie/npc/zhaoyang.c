// zhaoyang.c ������ʦ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIR"������ʦ"NOR, ({"master zhaoyang", "master"}));
       set("long", "��һ�����Ŵ�ʦ�֣��¸�¡�أ���Ϊ����������\n");
       set("title", HIC"��һ��"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 70);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�ϵ���");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
       set("max_force", 1800);
       set("force_factor", 180);
       set("max_mana", 1800);
       set("mana", 1800);
       set("mana_factor", 180);
       set("combat_exp", 1700000);
       set("daoxing", 2100000);

        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("spells", 220);  
        set_skill("tianmogong", 120);
        set_skill("literate", 120);
        set_skill("sword", 120);  
        set_skill("huxiaojian", 120);
        set_skill("zhaoyangbu", 120);
        set_skill("force", 120);   
        set_skill("huntianforce", 120);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");

	
	create_family("����ɽ", 2, "��");
	
	set("inquiry", ([
        "����"    : (: expell_me :),
        "leave"   : (: expell_me :),
	"name"     : "������һ�������ƽ̴���ӣ�����Գƺ��ҳ�����ʦ��\n",
	"here"     : "��������һ��������·�ˣ�\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
}

string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("class")=="sanjie") {
                message_vision("������ʦ���Ӷ���������ǳ��������㽫�ܵ������ͷ���\n", me);
                me->set_temp("sj_betray", 2);
                message_vision("������ʦ��$N�����ţ�С��������˵�������Ļ�(true)��\n", me);
                return ("�������ˣ��������ˣ�\n");
}
        return ("��ʲô�ʣ��Լ���ȥ��\n");
}
void init()
{     add_action("do_true", "true");
}

int do_true(string arg)
{
        if(this_player()->query("class") != "sanjie" )
                return 0;
        if(this_player()->query_temp("sj_betray") > 1 ) {
                message_vision("$N��������ӽ������Ļ���\n\n", this_player());
                message_vision("������ʦ̾�˿�����������ˣ������ɽ�ɣ�\n", this_player());
                this_player()->add("combat_exp", -(this_player()->query("combat_exp")/5));
                this_player()->add("daoxing", -(this_player()->query("daoxing")/5));
//                if( this_player()->query_skill("tianmogong") )
		    this_player()->delete_skill("tianmogong");
//                if( this_player()->query_skill("huntianforce") )
	            this_player()->delete_skill("huntianforce");
                    this_player()->delete_skill("huxiaojian");
                    this_player()->delete_skill("huxiaoquan");
                    this_player()->delete_skill("zhaoyangbu");
                    this_player()->delete_skill("zileidao");
                    this_player()->delete_skill("tianyaofa");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/sanjie", 1);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set("faith",0);
                this_player()->set_temp("sj_betray", 0);
                this_player()->save();
                message_vision("������ʦ����ֽ�$Nһ�ƣ�$N����һ�������򶫶�ȥ ... \n", this_player());
                this_player()->move("/d/sanjie/sanjiedao");
                tell_room( environment(this_player()),"������������¼����죬���¸�������\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="����ɽ") {
	if ((int)ob->query("daoxing") < 100000 ) {
  	command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ����\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���������ɣ��Ҳ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 25) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("tianmogong", 1) < 100 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "������ħ����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

�
