#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int give_me(object ob);
int delete_ask(object ob);
int create_pai(object ob);

void create()
{
       set_name("���޵�", ({"jing wudi", "jing"}));

set("long","��߰��ɣ������Բ���ųƶ�����һ��ʿ��
ˮ���������������Ʋ������ɳ�����ˮ�����С�\n");
       set("gender", "����");
       set("age", 56);
        set("title", "����");
        set("per", 10);
        set("str", 35);
	set("con", 30);
	set("int", 20);
        set("max_kee", 1500);
	set("max_sen", 1000);
       set("attitude", "heroism");
       set("combat_exp", 700000);
  set("daoxing", 200000);

       set_skill("unarmed",100);
       set_skill("dodge",100);
	set_skill("hammer", 150);
	set_skill("parry", 150);
	set_skill("force", 100);
	set_skill("spells", 100);
	set_skill("seashentong", 50);
	set_skill("dragonforce", 50);
	set_skill("dragonstep", 50);
	set_skill("literate", 50);
	set_skill("dragonfight", 50);
	map_skill("unarmed", "dragonfight");
	set_skill("huntian-hammer", 150);
	map_skill("hammer", "huntian-hammer");
	map_skill("parry", "huntian-hammer");
	map_skill("force", "dragonforce");
	map_skill("dodge", "dragonstep");
	map_skill("spells", "seashentong");
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
	set("have", 3);

    create_family("��������", 2, "ˮ��");
        set("inquiry", ([
                "����": (: give_me :),
                "pai": (: give_me :),
        ]) );

       setup();
       carry_object("/d/ourhome/obj/ironarmor")->wear();
       carry_object("/d/obj/weapon/hammer/bahammer")->wield();
	carry_object("/d/sea/obj/pai");
        remove_call_out("create_pai");
        call_out("create_pai",920,this_object());
}

void attempt_apprentice(object ob)
{
        command("look "+ ob->query("id"));
	command("nod");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

int give_me(object ob)
{
	object who, me,pai;
	who=this_player();
	me=this_object();
	pai=new("/d/sea/obj/pai");

	if( (string)who->query("family/family_name")!="��������" ) {
		if( (int)who->query_temp("pending/ask_time") >= 3) {
			message_vision("$NͻȻ���𣬶�ݺݵĵ���$n˵���������ǲ�����ˣ�\n", me, who);
			command("kill " + who->query("id"));
			return 1;
			}
		message_vision("$Nбб�����$nһ�ۣ�˵���˲���Ϊ���˵�Ҳ��\n", me, who);
		who->add_temp("pending/ask_time", 1);
		return 1;
	}     
       else {

	if( (int)who->query("combat_exp")+(int)who->query("daoxing") < 300 ) {
		command("baobao " +who->query("id"));
		return 1;
	}
       if( (int)who->query("jing_time")>time() )
           {
             message_vision("$Nҡ��ҡͷ����ղŲ����Ѿ�Ҫ������\n",me);
             return 1;
            }
       if(objectp(present("yao pai",who)))
           {
           	message_vision("$N���ɻ�ؿ�����˵���������ϲ����Ѿ�������\n",me);
           	return 1;
           }
	if( (int)me->query("have") ){
		command("nod "+who->query("id"));
		message_vision(CYN"$N�ó�һֻ���Ƹ�$n��\n"NOR,me,who);
		me->add("have", -1);
		pai->set("obj_owner",who->query("id"));
		pai->move(who);
	
		who->add_temp("pending/ask_time", 1);
                who->set("jing_time",time()+300);
              
		return 1;
		}
	}
	message_vision("$N��$n���ε�һ���֣�˵�����������ѷ����ˣ�����������ɡ�\n", me, who);
	return 1;
}


int create_pai(object ob)
{
	ob->set("have",3);
        remove_call_out("create_pai");
        call_out("create_pai",920,ob);	
	return 1;
}