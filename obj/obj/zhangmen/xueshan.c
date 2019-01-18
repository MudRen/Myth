//Cracked by Roath
// by snowcat 10/05/1997
// zhangmen.c ����
//modified for xueshan...

inherit NPC;
inherit F_SAVE;
#include <ansi.h>
string zm_apply();
string zname(object);
int rank_me();
#define DIRNAME "/obj/zhangmen/"
#define MYFILE "/obj/zhangmen/xueshan.c"


void create()
{
	set_name("�����", ({ "zhang men", "zhangmen" }) );
	set("gender", "����" );
	set("age", 30);
	set("str", 30);
	set("per", 30);
	set("int", 30);
	set("long", "���Ŵ���ӡ�" );
	set("attitude", "heroism");
	set("combat_exp", 100000);
	set("daoxing", 100000);
	set("current_player","none of us");

	setup();

	carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
	object me = this_object();

	me->create_identity("/d/xueshan/npc/dapeng", "/d/xueshan/xuelu");
	
	add_action("do_bandage","bandage");
             add_action("do_comfirm","comfirm"); 

	if (me->query("current_player")=="none of us")
		me->reset_me(me);    
	me->restore();
	me->fully_recover(me);

	me->set("inquiry", ([
		"name" : "ѩɽ�����Ŵ���ӣ�\n",
		"here" : "�Լ�����\n",
		"���Ŵ����" : (: zm_apply :),		
		"���ŵ���" : (: zm_apply :),	
		"�����" : (: zm_apply :),	
		"����" : (: zm_apply :),
		"ְλ": (: rank_me :),	 
	]) );

	me->setup();
}

void reset_me (object me)
{
	int i;
	object *inv;
	mapping skill_status, map_status;
	string *skillnames, *mapnames;
    
	reset_eval_cost();
	if ( mapp(map_status = me->query_skill_map()) )
	{
		mapnames = keys(map_status);
		for(i=0; i<sizeof(mapnames); i++)
		{
			me->map_skill(mapnames[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) )
	{
		skillnames = keys(skill_status);
		for(i=0; i<sizeof(skillnames); i++)  
		{
			me->delete_skill(skillnames[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		destruct (inv[i]);
	}

	me->set_name("�����", ({ "zhang men", "zhangmen" }) );
	me->set("gender", "����" );
	me->set("title",me->query("family/family_name")+zname(me));
	me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
	me->set("attitude", "heroism");
	me->set("current_player","none of us");

	me->set("str", 30);
	me->set("per", 30);
	me->set("int", 30);
	me->set("age", 30);

	me->set("weapon", 0);
	me->set("armor", 0);

	me->set_skill("force",  60); 
	me->set_skill("spells", 60); 
	me->set_skill("unarmed",60);
	me->set_skill("sword",  60);
	me->set_skill("dodge",  60);
	me->set_skill("parry",  60);

	me->set("max_gin", 600);
	me->set("eff_gin", 600);
	me->set("gin", 600);
	me->set("max_kee", 600);
	me->set("eff_kee", 600);
	me->set("kee", 600);
	me->set("max_sen", 600);
	me->set("eff_sen", 600);
	me->set("sen", 600);
	me->set("force", 600);
	me->set("max_force", 600);
	me->set("mana", 600);
	me->set("max_mana", 600);
	me->set("force_factor", 600);
	me->set("combat_exp", 100000);
	me->set("daoxing", 100000);

	me->setup();
	reset_eval_cost();

}

int save_record(object me, object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status;
	string *skillnames, *mapnames;
	int i, weapon_cnt, armor_cnt;

	reset_eval_cost();
	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]);
	me->set("per", hp_status["per"]);
	me->set("int", hp_status["int"]);
	me->set("age", hp_status["age"]);

	me->set("max_gin",     hp_status["max_gin"]);
	me->set("eff_gin",     hp_status["eff_gin"]);
	me->set("gin",         hp_status["gin"]);
	me->set("max_kee",     hp_status["max_kee"]);
	me->set("eff_kee",     hp_status["eff_kee"]);
	me->set("kee",         hp_status["kee"]);
	me->set("max_sen",     hp_status["max_sen"]);
	me->set("eff_sen",     hp_status["eff_sen"]);
	me->set("sen",         hp_status["sen"]);
	me->set("max_force",   hp_status["max_force"]);
	me->set("force",       hp_status["force"]);
	me->set("max_mana",    hp_status["max_mana"]);
	me->set("mana",        hp_status["mana"]);
	me->set("gender",      hp_status["gender"]);
	me->set("combat_exp",  hp_status["combat_exp"]);
	me->set("daoxing",  hp_status["daoxing"]);

	me->set("eff_gin", me->query("max_gin"));
	me->set("gin",     me->query("max_gin"));
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",   me->query("max_force")*2);
	me->set("mana",    me->query("max_mana")*2);

	skill_status = me->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames  = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++) 
		{
			me->delete_skill(skillnames[i]);
		}
	}

	skill_status = ob->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames  = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++) 
		{
			me->set_skill(skillnames[i], skill_status[skillnames[i]]);
		}
	}
  
	me->set("force_factor",me->query_skill("force")*3/4);

	reset_eval_cost();
	if (! me->query("new_player"))
	{
		me->save();
		reset_eval_cost();
		return 1;
	}

	me->set("new_player",0);

	if ( mapp(map_status = me->query_skill_map()) ) 
	{
		mapnames = keys(map_status);

		for(i=0; i<sizeof(mapnames); i++) 
		{
			me->map_skill(mapnames[i]);
		}
	}

	map_status = ob->query_skill_map();
	if ( mapp(map_status) ) 
	{
		mapnames  = keys(map_status);

		for(i=0; i<sizeof(mapnames); i++) 
		{
			me->map_skill(mapnames[i], map_status[mapnames[i]]);
		}
	}
  
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) 
	{
		destruct(inv[i]);
	}

	// save once here, an external bug might stop the following
	me->setup();
	me->save();


	weapon_cnt = 0;
	armor_cnt = 0;
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) 
	{
		if ( !inv[i]->query_unique() && 
		inv[i]->query("skill_type") &&
		inv[i]->query("equipped") && !weapon_cnt ) 
		{
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				if(obj->move(me)) // mon 8/13/97
				obj->wield();
				obj->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
			}
			me->set("weapon", base_name(inv[i]));
			weapon_cnt = 1;
		}
		else if ( !inv[i]->query_unique() && 
		!inv[i]->query("skill_type") && 
		inv[i]->query("equipped") && !armor_cnt ) 
		{
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				if(obj->move(me))
				obj->wear();   //mon 8/13/97
				obj->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
			}
			me->set("armor", base_name(inv[i]));
			armor_cnt = 1;
		}
		else if( weapon_cnt && armor_cnt )
			break;
	}

	me->setup();
	me->save();
	reset_eval_cost();

	return 1;
}

int convert_identity (object me, object ob)
{
	object who;

	reset_eval_cost();

	who = find_player(me->query("current_player"));
	if (! who)
	{
		// nobody to recover
	}
	else if (who->query("zhangmen/title_old"))
	{
		who->set("title",who->query("zhangmen/title_old"));
	}
	else if (who->query("family/family_name"))
	{
		who->set("title",
			sprintf("%s��%s��%s",
			who->query("family/family_name"),
			chinese_number(who->query("family/generation")),
			who->query("family/title")));
		who->save();
	}
	ob->set("zhangmen/base_name",base_name(me));
	ob->set("zhangmen/data_name",me->query_save_file());
	ob->set("zhangmen/title_old",ob->query("title"));
	ob->set("zhangmen/title",ob->query("family/family_name")+zname(ob));
	ob->set("title",ob->query("family/family_name")+zname(ob));
	ob->save();

	me->reset_me(me);
	me->set("name", ob->query("name") );
	me->set("gender", ob->query("gender") );
	me->set("current_player",ob->query("id"));
	me->set("title",ob->query("family/family_name")+zname(ob));
	me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");

	save_record(me, ob);

	return 1;
}

void self_adjust (object me)
{
	mapping skill_status;
	string *skillnames;
	int i;

	me->set("max_gin", 600);
	me->set("eff_gin", 600);
	me->set("gin", 600);
	me->set("max_kee", 600);
	me->set("eff_kee", 600);
	me->set("kee", 600);
	me->set("max_sen", 600);
	me->set("eff_sen", 600);
	me->set("sen", 600);
	me->set("force", 600);
	me->set("max_force", 600);
	me->set("mana", 600);
	me->set("max_mana", 600);
	me->set("force_factor", 60);
	me->set("combat_exp", 100000);
	me->set("daoxing", 100000);

	skill_status = me->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++)
			me->set_skill(skillnames[i], 60);
	}

	carry_object("/d/obj/cloth/linen")->wear();
	me->save();

}

int init_identity (object me, object master, object where)
{
	mapping skill_status;
	string *skillnames;
	int i;

	reset_eval_cost();
	me->setup();

	me->move(where);
	me->set("where",base_name(where));

	me->set("gender", master->query("gender") );
	me->set("current_master",master->query("id"));
	me->set("current_master_base_name",base_name(master));
	me->set("family/generation",master->query("family/generation"));
	me->set("family/family_name",master->query("family/family_name"));
	me->set("title",me->query("family/family_name")+zname(me));
	me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");

	me->restore();
	if (me->query("current_player")!="none of us")
		return 1;

	remove_call_out("self_adjust");
	call_out("self_adjust", 1, me);

	me->reset_me(me);
	me->set("new_player",1);
	save_record(me, master);

	return 1;
}

object find_and_restore (string name)
{
	object me = find_object(name);

	if (! me || ! me->restore())
		me = new (name);
	me->setup();
	return me;
}

int fully_recover (object me)
{
	object *inv;
	object ob;
	string player_name;
	object current_player;

	reset_eval_cost();

	me->set("eff_gin", me->query("max_gin"));
	me->set("gin",     me->query("max_gin"));
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",   me->query("max_force")*2);
	me->set("mana",    me->query("max_mana")*2);

	player_name = me->query("current_player");
	if (! player_name || player_name == "none of us")
		return 1;
  
	if (current_player = find_player(player_name))
	{
		if (current_player->query("combat_exp")>me->query("combat_exp"))
			save_record (me, current_player);
	}
	else if (current_player = LOGIN_D->find_body(player_name))
	{
		if (current_player->query("combat_exp")>me->query("combat_exp"))
			save_record (me, current_player);
	}
	else
	{
		seteuid(player_name);
		current_player = new(USER_OB);
		current_player->set("id", player_name);
		if (!current_player->restore())
		{
			destruct(current_player);
			return 1;
		}
		export_uid(current_player);
		seteuid(getuid());
		current_player->setup();
		if (current_player->query("combat_exp")>me->query("combat_exp"))
			save_record (me, current_player);
		destruct (current_player);
	}

	inv = all_inventory(me);
	while (inv && sizeof(inv))
	{
		destruct (inv[0]);
		inv = all_inventory(me);
	}

	if (me->query("weapon"))
	{
		ob = new(me->query("weapon"));
		if(ob->move(me))
			ob->wield();  
		ob->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
	}

	if (me->query("armor"))
	{
		ob = new(me->query("armor"));
		if(ob->move(me))
			ob->wear();
	       ob->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");	
	}

	reset_eval_cost();
	return 1;
}

string zm_apply()
{
	object me = this_object();
	object ob = this_player();

	if (me->query("family/family_name") != ob->query("family/family_name")) 
	{
		return "�ұ��Ǳ������ŵ��ӣ�\n";
	}
	if (ob->query("betrayer") || ob->query("betray/count"))
	{
		return "������ʦ���棬�������в��죬���ܳ������ŵ���һְ��\n";
	}
	if (me->query("current_player") == ob->query("id")) 
	{
		return "���ֺ�Ϳ�ˣ�\n";
	}

	ob->set_temp("xueshan_zm_applied", 1);
	return "�����ŵ������λ������Ȥ���Ǿͷ���һս�ɣ�\n";
}

int accept_fight(object ob)
{
	int i;
	object* inv;

	object me = this_object();


	if (me->query("current_player") == ob->query("id")) 
	{
		return notify_fail("���ֺ�Ϳ�ˣ�\n");
	}

	if (me->is_fighting())
	{
		command ("say ʧ���ˣ�\n");
		return notify_fail("��λ��������ڱ���֮�У����Ժ�\n");
	}

	if (ob->query_temp("xueshan_zm_applied"))
	{
		command("say �ߣ�����δ����"+zname(ob)+"�������顣\n");
	}
	else
	{
		command("say �ã����Ǿ��д�һ�¡�\n");
	}

	me->set_temp("zhangmen/kill",0);
	remove_call_out("check_result");
	call_out("check_result", 1, me, ob);
  
	fully_recover (me);
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) 
	{
		if( inv[i]->query_unique() ) {
			message_vision("ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n",me,inv[i]);
			destruct(inv[i]);
		}
	}

	return 1;
}

int check_result(object me, object ob)
{
            string week, month, year, day, time;  
	int my_max_kee, his_max_kee;

	my_max_kee  = me->query("max_kee");
	his_max_kee = ob->query("max_kee");

	if (me->is_fighting())
	{
		call_out("check_result",1, me, ob);
		return 1;
	}

	if ( !living(me) 
		|| (int)me->query("kee") < 1 
		|| (int)me->query("sen") < 1 ) return 1;

	if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
	{
		object who;

		if ( !living(me) 
			|| (int)me->query("kee") < 1 
			|| (int)me->query("sen") < 1 ) return 1;

		message_vision ("$N�����°ݣ����������\n",me);

		if (me->query_temp("zhangmen/kill") && ob->query_temp("xueshan_zm_applied"))
		{
			message_vision ("$N������ü�����˴α�����δ�ܾ��ľ�����ϣ������������\n", me);
			return 1;
		}

		if( ob->query_temp("xueshan_zm_applied") != 1 )
			return 1;	
  sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);  
   if(day=="")  
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);   
  
//
      if(week!="Mon" && week!="Sun" ) 
      { 
      message_vision ("$N������ü�������첻����һ�����գ��´��ڴ�\n", me);  
      return 1;} 
	
		if (me->query("current_master"))
		who = present(me->query("current_master"),environment(me));
		if (who && who->query("id")!=me->query("current_master"))
			who = 0;

		if (who)
		{ 
			call_out("master_announce",1,me,who,ob);
		}
		else
		{
			message_vision ("$N�����$n˵��������ݼ�ʦ����\n",me,ob);
			command ("follow "+ob->query("id"));
			if (! me->query("where"))
				me->set("where",base_name(environment(me)));
			remove_call_out("find_master");
			call_out("find_master", 1, me, ob);
		}
		return 1;
	}

	if (( (int)ob->query("kee")*100/his_max_kee)<=50)
	{
		message_vision ("$N��$n����\n",me,ob);
	}

	return 1;  
}

void find_master (object me, object ob)
{
	object who = present(me->query("current_master"),environment(me));

	if (who && who->query("id")!=me->query("current_master"))
		who = 0;

	if (! who)
	{
		remove_call_out("find_master");
		call_out("find_master", 1, me, ob);
	}
	else
	{
		message_vision ("$N����ʦ���Ͻ��°ݣ���̧��ͷ��$nʹ�˸���ɫ��\n\n",me,ob);
		message_vision ("$N΢΢�ص��˵�ͷ��\n\n",who);
		message_vision ("$N���¡�\n\n",me);
		me->set_leader(0);
		call_out("master_announce",1,me,who,ob);
		me->move(me->query("where"));
	}
}

void master_announce (object me, object who, object ob)
{
	CHANNEL_D->do_channel(who,"chat","�������ŵ���"+ob->query("name")+"�����������Ρ������λ�ɳ����������");
	ob->delete_temp("xueshan_zm_applied");
	me->set("new_player",1);
	convert_identity (me, ob);
}

string query_save_file()
{
	string str = query("save_file");
	int i;

	if (str)
		return str;

	str = DATA_DIR+"zhangmen/zhangmen_"+query("current_master");
	for (i = 0; i < sizeof(str); i++)
		if (str[i]==' ') str[i] = '_';

	return str;
}

void set_save_file(string str)
{
	set("save_file",str);
}

int do_bandage(string arg)
{
	object who = this_player();
	object me = present("zhang men",environment(who));

	if (! arg || me != present(arg, environment(me)))
		return 0;

	message_vision ("$N�������ĵ�Ҫ��$n�����˿ڡ�\n",who,me);
	call_out("no_bandage",2,who,me);
	return 1;
}

void no_bandage(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

void kill_ob(object ob)
{
	object me = this_object();
	object master;

	if (me->query("current_master"))
		master = present(me->query("current_master"),environment(me));
	if (master)
		master->kill_ob(ob);
	else
	{

	}
		
	me->set_temp("zhangmen/kill",1);
	::kill_ob(ob);
}

void create_identity (mixed master, mixed where)
{
	object master_ob, where_ob;

	if (this_object()->query("created"))
		return;
	this_object()->set("created",1);

	if (objectp(master))
		master_ob = master;
	else
	{
		master_ob = new (master);
		master_ob->restore();
	}

	if (objectp(where))
		where_ob = where;
	else
	{
		call_other(where,"???");
		where_ob = find_object(where);
	}
	init_identity (this_object(), master_ob, where_ob);
}

string zname(object ob)
{
	if( (string)ob->query("gender") == "Ů��" ) 
		return "��ɽ�������";
	else return "�޷������аʥ";
}
int rank_me()
{
	object me=this_player();
	object ob=this_object();
	int exp,dx;
	exp=(int)me->query("combat_exp");
	dx=(int)me->query("daoxing");
	exp=exp+dx;
        if( me->query("title") == "��ѩɽ��ɽ�������"
          ||me->query("title") == "��ѩɽ�޷������аʥ")
		return notify_fail("���Ѿ���������ݣ�����Ҫʲôְλ��\n");
	if( me->query("family/family_name") == "��ѩɽ")
	{
                if( exp <= 40000 ){
			me->set("title", "��ѩɽ����С��");
		} else if(exp <= 100000 ){
			me->set("title", "��ѩɽ��ɽС��");
		} else if(exp < 200000 ){
			me->set("title", "��ѩɽС��ͳ��");
		} else if(exp <= 400000 ){
		       if(me->query("gender") == "����"){	
			me->set("title", "��ѩɽ����ʹ��");
		       }
		       else me->set("title","��ѩɽ����ħŮ");
		} else if(exp <= 1000000 ){
		       if(me->query("gender") == "����"){
			   me->set("title", "��ѩɽ�嶾���");
		       }
		       else me->set("title","��ѩɽ�ٳ��ȸ����");
		} else if(exp <= 2000000 ){
			me->set("title", "��ѩɽ������ɷ");
		} else if(exp <= 4000000 ){
			me->set("title", "��ѩɽ��������");
		} else {
			me->set("title", "��ѩɽ�������");
		}

		tell_object(me, HIR""+ob->query("name")+"����˵���������"+me->query("title")+"��\n"NOR);
		tell_room(environment(me),
HIR""+ob->query("name")+"��"+me->query("name")+"˵���������"+me->query("title")+"��\n"NOR, ({me, me}));
        }
	return 1;
}

int do_comfirm()  
{   
      object me=this_player(); 
 
     object ob=this_object(); 
  
    string week, month, year, day, time;  
   
      
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);  
   if(day=="")  
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);   
  
        if (ob->query("current_player") != me->query("id"))  
         {       
      message_vision ("$N��$n������ü���������ڲ�����ְ���ţ���������Ϲ�죡\n",ob,me);  
           return 1;} 
      if(week!="Mon" && week!="Sun" ) 
      { 
      message_vision ("$Nϲ��������֪ͨʦ���������Ÿ����ˣ�\n",ob,me);  
        me->set_temp("zhangmen_damage",1); 
      return 1;} 
       
               message_vision ("$N���������Ǳ����գ�����������ȷ�ϣ�\n",ob,me);  
              return 1; 
}  
 
