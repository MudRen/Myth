//liuer-mihou.c weiqi...98/05/13

#include <ansi.h>
#define MAX_TRY 20
inherit NPC;
string ask_me();

void create()
{
	set_name("����⨺�", ({"liuer mihou", "liuer", "mihou"}));
	set("title", "��ͨ��");
	set("gender", "����" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	set("long", "����⨺����������Ԫ�������£�ѧ��һ��ñ��졣\n�������Ծ�����Ԫ���ɲ���ˣ��㿪ʼ������������\n��Ȼȥ��԰͵���˲ι�������ǹ���û���ŷ�������Ԫ���ɴ�ס��\nʹ�ӳ�����������ǽ��\n");
	set("class", "xian");
	set("combat_exp", 1500000);
	set("attitude", "peaceful");
	//create_family("��ׯ��", 2, "����");
	set("rank_info/respect", "��ү");
	set_skill("unarmed", 180);
	set_skill("wuxing-quan", 180);
	set_skill("dodge", 150);
	set_skill("baguazhen", 150);
	set_skill("parry", 180);
	set_skill("hammer", 160);
	set_skill("kaishan-chui", 180);
	set_skill("force", 160);   
	set_skill("zhenyuan-force", 160);
	set_skill("literate", 150);
	set_skill("spells", 180);
	set_skill("taiyi", 180);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("dodge", "baguazhen");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force", 2000);
	set("max_force", 2000);
	set("mana", 2000);
	set("max_mana", 2000);	
	set("force_factor", 50);
	set("mana_factor", 80);

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	set("chat_chance_combat", 30);
	set("chat_msg_combat", 
	({
		(: cast_spell, "zhenhuo" :),
	}) );

	set("inquiry", ([
		"name": "�����ʥ�������Ҳ��\n",
		"here": "������\n",
		"�˲ι�": "��ү����ϲ���ľ����˲ι���\n",
		"ɱ��": "ɱ�ˣ�ֻҪ�����˲ι���ʲô����������\n",
		"�ؾ�": "�ؾ���ֻҪ�����˲ι���ʲô����������\n",
		"⨺��ּ�": "�ּǣ�ֻҪ�����˲ι���ʲô����������\n",
//                "����"     : (: ask_me :),
//                 "���"     : (: ask_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}

int accept_object(object me, object ob)
{
	object book;

	if ( (string)ob->query("id") != "renshen guo" ) {
		message_vision("����⨺�����е���ȥ��ȥ��ȥ����Һ�үû�����㣡\n", me);
		command("kick " + me->query("id"));
		//call_out("do_drop", 2, ob);
		return 1;
	}

	else {
            if(ob->query("fake")) {
                command("kick " + me->query("id"));
                message_vision("����⨺�����е���ȥ��ȥ��ȥ����Һ�үû��ô�����ϵ���\n", me);
              return 1;
                                    }
		command("jump ");
		command("say ��λ" + RANK_D->query_respect(me) + "��Ȼ��ʹ���ˣ�\n");
		//first give a book...
		book = new("/d/obj/book/mihou-book");
		book->move(me);
		message_vision("$N��$n�����Ǻ�ү��Ҳ����С����˵�յݸ�$nһ��С���ӡ�\n�����Ȿ���⣬����Ұﲻ�ϣ���ɱ������û����ġ���Ҫɱ�˵Ļ������ɸ���˵��(whisper liuer enemy_id)��\n", this_object(), me);
		me->set_temp("rsg_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

void relay_whisper(object me, string msg)
{
	object target, where;

	if (me->query_temp("rsg_given") != 1)
	{
		message_vision((string)this_object()->query("name") + "����$N����ؿ���һ�ۡ�\n", me);
		return;
	}

	if( query_temp("I_am_busy") == 1 )
	{
		message_vision((string)this_object()->query("name") + "��$N������������æ�ţ���Ȼ������ɡ�\n", me);
		return;
	}

	
	target = find_player(msg);
	if( !target )
	{ 
		message_vision((string)this_object()->query("name") + "��$N˵���������Ҳ�������ˡ�\n", me);
		return;
	}

	where = environment(target);
	if( !where )
	{ 
		message_vision((string)this_object()->query("name") + "��$N˵������������У����Ƕ������ˡ�\n", me);
		return;
	}

	//now got the target player...
	message_vision((string)this_object()->query("name") + "��$N˵�����ã���;�������ɣ�\n", me);

	me->delete_temp("rsg_given");
	set_temp("I_am_busy", 1);
	set_temp("kill_count", MAX_TRY);

	remove_call_out ("try_kill");
	call_out ("try_kill", 3, msg);
	call_out ("check_finish", 3, msg);
	//note, here we still use target id for future trying...
}

void check_finish(string target_id)
{
	object target;

	//here alway set fali back, since liuer mihou is in a "bian" status...
	if( (int)this_object()->query("mana") < (int)this_object()->query("max_mana") )
		this_object()->set("mana", 2*(int)this_object()->query("max_mana"));

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}

	if( target->is_ghost() )
	{//means the target is dead.
		//bian back now...
		command("bian");
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		remove_call_out ("try_kill");
		remove_call_out ("check_finish");
		return;
	}
	else
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}
}

void  try_kill(string target_id)
{
	object target, where;

	if( (int)query_temp("kill_count") <= 0 )
	{//tried too long
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		return;
	}

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	where = environment(target);
	if( !where )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	//now kill...
	if( where != environment(this_object()) )
	{
		this_object()->move(where);
		message_vision(YEL "ֻ����������һβ�ֹ��$Nһ������˳�����\n" NOR, this_object());
	}
	message_vision(RED "$Nץ�������ض�$n����˵�������������Ƕ��ݹֺ�ү���顣����Ҫ�����˲ι���һ��������ɱ�ˡ�\n" NOR, this_object(), target);

	if( (int)query_temp("kill_count") == MAX_TRY ) 
	{//first time, always need to initialize kill...
		command("bian " + target_id);
		//this_object()->kill_ob(target);
		//need consider this carefully, is it ok to make safe place unsafe?
		command("kill " + target_id);
	}
	else command("kill " + target_id);
	//problem here, if kill_ob(), may bypass no_fight, ...etc;
	//if kill command, may confuse with NPC of the same name?
	command("follow "+target_id);

	set_temp("kill_count", (int)query_temp("kill_count")-1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 900, target_id);//try every 15 minutes.
}

//LPG 19990925 ���������
/*
string ask_me()
{
	this_player()->set_temp("liuer-mihou_ask","done");
	call_out("autokill",1,this_player(),this_object());
	return "�ٺ�";
}
void autokill (object me, object who)
{
  message_vision ("$n���һ��Ҫɱ��$N��\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N��ŭ���ĸ�������ð����Һ�ү��\n",this_player());

  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
}

void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object xiangjiao;
  message_vision(HIY "\n����ͻȻ�Ӳ��Ƽ�����\n" NOR,me);
  message_vision(HIY "\n������$Nһ���֣������ͷ��\n" NOR,me);
  message_vision(HIY "$N��ѽһ������������\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
  	ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
	message_vision(HIC "����˵���������Ҵ��ߣ��㰲��ȡ��ȥ�ɡ�\n\n" NOR,me);
  	xiangjiao = new ("/d/obj/drug/xiangjiao");
       xiangjiao -> move(ob);
	message_vision("$N����һЩ������\n\n",me);
  	call_out ("guan_appearing",1,ob);
  }
  ob->set_temp("liuer-mihou_ask","no");
  message_vision("$N�㬵����ˡ�\n\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}
*/
void guan_appearing (object who)
{
  object guan = new ("/d/nanhai/npc/guanyin");
  guan->announce_success (who);
  destruct (guan); 
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}
