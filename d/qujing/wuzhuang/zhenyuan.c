// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0

inherit NPC;
inherit F_MASTER;

string expell_me(object me);
string keyword(object me);
string asked_guo(object me);

void create()
{
	set_name("��Ԫ����", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
	set("title", "��ׯ�۹���");
	set("gender", "����" );
	set("age", 65);
	set("per", 24);
	set("str", 30);
	set("long", "���α����磬���������С���һλ����֮�棡\n");
	set("class", "xian");
	set("combat_exp", 2800000);
	set("daoxing", 10000000);

	set("attitude", "peaceful");
	create_family("��ׯ��", 1, "��ʦ");
	set("rank_info/respect", "����");
	set_skill("unarmed", 180);
	set_skill("wuxing-quan", 200);
	set_skill("dodge", 150);
	set_skill("baguazhen", 160);
	set_skill("parry", 180);
	set_skill("sword", 160);
	set_skill("sanqing-jian", 190);
	set_skill("staff", 160);
	set_skill("fumo-zhang", 190);
	set_skill("hammer", 160);
	set_skill("kaishan-chui", 190);
	set_skill("blade", 160);
	set_skill("yange-blade", 190);
	set_skill("force", 180);   
	set_skill("zhenyuan-force", 180);
	set_skill("literate", 180);
	set_skill("spells", 200);
	set_skill("taiyi", 200);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("dodge", "baguazhen");
	map_skill("staff", "fumo-zhang");
	map_skill("blade", "yange-blade");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 4500);
	set("max_sen", 4500);
	set("force", 5000);
	set("max_force", 2500);
	set("mana", 7000);
	set("max_mana", 5000);	
	set("force_factor", 100);
	set("mana_factor", 250);

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	set("chat_chance_combat", 60);
	set("chat_msg_combat", 
	({
		//(: cast_spell, "zhenhuo" :),
		(: cast_spell, "qiankun" :),
	}) );

	set("inquiry", ([
		"leave": (: expell_me :),
		"�뿪": (: expell_me :),
		"����Ǭ��": (: keyword :),
		"�ؾ�": (: keyword :),
		"name": "�Ϸ���Ԫ��\n",
		"here": "��������ׯ�ۣ�����ס�Ŀɲ��ǵ�ʿ��\n",
		"�˲ι�": (: asked_guo :),
	]) );

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/ruler")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="dao" )
	{
		command("say �ã��ã����ɱ�һ�ҡ�\n");
	}

	if( (string)ob->query("family/family_name")=="��ׯ��" )
	{
		if( (int)ob->query("family/generation") > 3   )
		{
			command("say ��»������������ռ������ӣ����ȵ��Ǳ߿����ɡ�\n");
		}
		else 
		{
			if( (int)ob->query("combat_exp")+(int)ob->query("daoxing") >= 600000 && (int)ob->query_skill("taiyi", 1) >= 120 )
			{
				command("nod ");
				command("say �ã�" + RANK_D->query_respect(ob) + "�����Ǳ��ŵ��˲ţ�\n");
				command("recruit " + ob->query("id") );
			}
			else
			{
				command("say �����Ͻ��ǲ�����������Ҫѭ�򽥽���\n");
			}
		}
	}

	else
	{
		command("nod");
		command("say ��λ" + RANK_D->query_respect(ob) + "�����Ž�������֮����֮�֡�һ�������Ϊ�������ӿ����Ĳ�����\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

string expell_me(object me)
{       
	me=this_player();
	if((string)me->query("family/family_name")=="��ׯ��") {
		message_vision("��Ԫ���ɵ������ȻҪ�ߣ���Ҳ����ǿ��������̫���ɷ�����ׯ�۲���֮�أ��ɲ��ܴ������⡣\n", me);
		me->set_temp("asked_leave_wzg", 1);
		return ("�������Ҫ��(true)��\n");
	}
	return ("��磬���£��Ϳͣ�\n");
}

string keyword(object me)
{       
	me=this_player();
	if((string)me->query("family/family_name")=="��ׯ��") {
		message_vision("��Ԫ���ɵ�������ָ����Ǭ������������ɡ�\n", me);
		if( me->query("spell_qiankun_on") == 1 ) return ("�����Ѿ�����������\n");
		if( (int) me->query("combat_exp") < 10000 ) return ("�����ڵ���̫�ͣ�ʩ������Ǭ����Σ��������\n");
		if( (int) me->query("max_mana") < 300 ) return ("�����ڷ���̫�ͣ�ʩ������Ǭ����Σ��������\n");
		message_vision("��Ԫ���ɵ����ã�������...�԰�������$Nͷ��һ�ģ�\n", me);
		me->set("spell_qiankun_on", 1);
		return ("��������Ѿ��������ˣ�ȥ�գ�\n");
	}
	command("kick");
	return ("���̽�����ؼ����ô�ĵ��ӣ�\n");
}


void init()
{
	add_action("do_true", "true");
	add_action("do_back", "back");
}

int do_true(string arg)
{
	if(this_player()->query_temp("asked_leave_wzg")) {
		message_vision("$N���������������ߣ�\n\n", this_player());
		message_vision("��Ԫ����̾�˿��������ã��������ǿ͡�\n", this_player());
		this_player()->add("betray/wuzhuangguan", 1);
		this_player()->add("betray/count", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		this_player()->delete_skill("taiyi");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("asked_leave_wzg", 0);
		this_player()->save();
		message_vision("˵����$Nͷ��һ����$Nֻ������һ�ᣬ�յ����غ�����ʲô��\n", this_player());
		return 1;
	}
	return 0;
}

//the following is for renshen dahui...

void announce (object me, string str)
{
	if (DEBUG)
	{ 
		object weiqi = find_player ("weiqi");
		if (weiqi && wizardp(weiqi))
			tell_object (weiqi,"�� "+str+"\n");
	}
	else
	{
		CHANNEL_D->do_channel(me,"chat",str);
	}
}

void start_renshen()
{
	object me;

	me = this_object();
    
	set_temp("invite","public");

	set_name("��Ԫ����", ({"zhenyuan_daxian", "zhenyuan daxian", "zhenyuan", "daxian"}));
	setup();

	announce (me, "��ׯ���˲ι�Ʒ����ἴ����ʼ��\n");
	announce (me, "��λ������Ը����ʹaccept zhenyuan_daxian��ɣ�\n");
	remove_call_out ("inviting");
	call_out ("inviting",1,me);

	call_out("ready1", 180);
	set_temp("ready0", 1);
}

void ready1()
{
	object me;

	me = this_object();

	announce (me, "��ׯ���˲ι�Ʒ��������Ͼ�Ҫ��ʼ��\n");
	announce (me, "��λ������Ը����ʹaccept zhenyuan_daxian��ɣ�\n");
	call_out("ready2", 180);
	set_temp("ready1", 1);
}

void ready2()
{
	object me;

	me = this_object();

	announce (me, "��ׯ���˲ι�Ʒ��������ڿ�ʼ��\n");
	announce (me, "��λ������Ը����ʹaccept zhenyuan_daxian��ɣ�\n");
	set_temp("ready2", 1);
}

string asked_guo(object me)
{ 
	int i, total;
	object guo;
	object *inv ;
      
	me=this_player();

	//if no renshenguo party at all...
	if( query_temp("ready0") != 1 ) return ("�˲ι����Ǹ��ö�����\n");

	//if not in the right place, no guo...
	//need the right name, also right outdoors(so ppls can not use fake room).
	if( (environment(this_object()))->query("short") != "�˲ι�԰" || 
		(environment(this_object()))->query("outdoors") != "wuzhuang" )
	{
		return ("�����ֲ��ǹ�԰���������˲ι���\n");
	}

	//if waiting for ppls...
	if( query_temp("ready1") != 1 ) return ("��Ҫ�����ٵȵȡ�\n");

	//if ready to begin...
	if( query_temp("ready2") != 1 ) return ("��Ҫ�������Ͼ��С�\n");

	//if finished...
	if( query_temp("finished") == 1 ) return ("�˲ι��ѷַ����ˡ�\n");

	//now check how many people here...
	total = 0;
	inv = all_inventory( environment(this_object()) );
	for(i=0; i<sizeof(inv); i++)
	{
		if( userp(inv[i]) && (!wizardp(inv[i]))  ) total++;
	}

	if( total > 3 ) return ("��ѽ����ô���ˣ�����ֻ����ö������˲ι���\n");
	else if ( total <= 3 && total > 0 )
	{
		for(i=0; i<sizeof(inv); i++)
		{
			if( userp(inv[i]) && (!wizardp(inv[i]))  ) 
			{//wiz not counted...
				guo = new("/d/obj/drug/renshen-guo");
				guo->move(inv[i]);
				message_vision("$N��$nһö�˲ι���\n", this_object(), inv[i]);
				announce (this_object(), "��ϲ��ϲ��" + inv[i]->query("name") + "����˲ι�һö��\n");
			}
		}

		set_temp("finished", 1);
		call_out("finishing", 5);

		return ("�ã��˲ι��ַ���ϣ���λ���;������ðɡ�\n");
	}
	else return ("˭Ҫ�˲ι���\n");
	
}

void finishing()
{
	message_vision("$N������Ц��������ʱ��Ӱ�����ˡ�\n", this_object());
	delete_temp("invite");//this is necessary if not going to destruct this obj.
	destruct(this_object());
}

void inviting (object me)
{
	int i,accept_time,exp;
	object *list;
     

	if (! me->query_temp("invite"))
	return;
  
	remove_call_out ("inviting");
	call_out ("inviting",4+random(4),me);

	list = users();
	i = sizeof(list);
	while  (i--)
	{
		string here, there;

		reset_eval_cost();

    
		if (!environment(list[i]))
			continue;
    
		if (environment(list[i])->query("unit")) // not a room
			continue;
	       exp=list[i]->query("daoxing")+list[i]->query("combat_exp");
              if (exp<10000) continue;
		if (list[i]->is_fighting())
			continue;
    
		if (list[i]->is_busy())
			continue;
    
		if (list[i]->query_temp("no_move"))
			continue;
    
		if (list[i]->is_ghost())
			continue;
    
		if (!living(list[i]))
			continue;
    
		if ((string)list[i]->query_temp("accept")!=me->query("id"))
			continue;

		list[i]->set_temp("accept",0);
		here = (string)environment(me);
		there = (string)environment(list[i]);
		if (here == there)
			continue;

		message_vision("$N�Ĵ�������һ�֡�\n",me);
		list[i]->set_temp("accept",0);
		list[i]->set_temp("wzg/from",there);

		message_vision("һ������Ʈ�����������һֻ�޴�����佫$N����һ�֣���ʧ����ա�\n",list[i]);
              accept_time=list[i]->query("rsg/accept_time");
              if ( accept_time && accept_time>time() ) 
                 {
                   message_vision("�����ͻȻ���һֻ��ţ���$Nһ���߷��ڵ��ϣ���Լ����������һ���ƺߣ�\n",list[i]);
                                 continue;
                              }
    		list[i]->move(here);
		message_vision("��$N��������һ����$n���˳�����\n",me,list[i]);
              list[i]->set("rsg/accept_time",time()+86400);
		break;
	}
}

int do_back(string arg)
{
	object who = this_player();
	object me = this_object();
	string here = (string)environment(me);
	string there = who->query_temp("wzg/from");

	message_vision("$N����$n��$N�ط���\n",who,me);
 
	 //if (!there)
	// there = "/d/city/kezhan";
	there = "/d/city/kezhan";

	who->set_temp("accept",0);
	message_vision("$N�Ĵ��䳯��$n����һ�֡�\n",me,who);
	who->move(there);
	message_vision("���������һֻ�޴����������һ����ֻ��$N�����滬�˳�����\n",who);
  
	return 1;
}


�
