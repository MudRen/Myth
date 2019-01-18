// chunyang.c ������ʦ

#include <ansi.h>
string ask_me();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"������ʦ"NOR, ({"master zhaoyang", "master"}));
       set("long", "��һ�������ˣ��İ���ǰ��һ��֮����������ħ��\n");
       set("title", HIC"��һ��"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����ʦ");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 200);
        set_skill("parry", 160);
        set_skill("spells", 160);  
        set_skill("tianmogong", 160);
        set_skill("literate", 160);
        set_skill("sword", 200);  
        set_skill("huxiaojian", 200);
        set_skill("zhaoyangbu", 200);
        set_skill("force", 160);   
        set_skill("huntianforce", 160);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

	create_family("��һ��", 1, "��");
	
	set("inquiry", ([
	"name"     : "�Ϸ�����һ�������ˡ�����������\n",
	"here"     : "������һ�ɸ�Ҳ���ܽ�����Ҳ���㸣��ǳ��\n",
	"�ڵ�"     : (: ask_me :),
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/sanjie/obj/xuantian");	
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/chunyang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="��һ��") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ����\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���������ɣ��Ҳ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("huntianforce", 1) < 120 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "�Ի��챦����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
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

string ask_me()
{
        object ob;
           
   if((int)this_player()->query("combat_exp") < 30000 )
     return "�㹦����ǳ���������������Ժ���˵�ɣ�\n";

   if (this_object()->is_fighting())
     return "û���Ϸ����������Ժ���˵�ɣ�\n";

   if ( present("neidan", this_player()) )
     return "�ԣ��ԣ��ԣ����㵤���ܲ��ˣ��书ȫ�ϣ�\n";

        if ( present("neidan", environment()) )
     return "�ǲ�����һ�����������˵��\n";

   if(query("time") <1 )
     return "���ɣ����ɣ���Ҳû�ˣ�\n";

     say("������ʦ˵�����ǵ�Ҫ���㹻��������ˣ���������ɣ�\n");
     this_player()->set_temp("chunyang_fight", 1);
     return ("�ٺ٣�\n");
}

int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("chunyang_fight")){
     command("say ���򲻴�û���Ϸ���������\n");
         return 0;
   }
     if (me->is_fighting()){
     command("say ���򲻴�\n");
         return 0;
   }
   say("����Ц������ͷ�ӵ��˼������ˣ����ǵȵ�һ���г�Ϣ�ģ�\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("chunyang_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
     object obj;
   if (me->query("time")<=0)
     return;
   obj=new("/d/sanjie/obj/neidan");
   say("������ʦ�����Ц���������������˼������ˣ������ҵ��̳����ˣ�\n");
   say("������ո�ǿ���������ҵ��������\n");
   obj->move(who);
        me->add("time", -1);
   message_vision("������ʦ��$N����Ц���������Ҿʹ����Ϸ���İ��깦���������°ɣ�\n", who);
   call_out("reg", 750);
}

int reg()
{
   object me=this_object();
   me->set("time", 1);
   return 1;
}

void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("������ʦ������Ц��"+msg+"ĪҪ�����ˣ���ȥ�ú�����ɣ����շ����\n");
}

void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

   if (!present(who, environment(me)))
         return;

   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
     else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

�
