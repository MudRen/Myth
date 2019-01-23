//Cracked by Roath
//��������

inherit NPC;
string ask_me();
void create()
{
        set_name("����", ({"shou xing", "xing"}));
	set("title", "��������");
	set("gender", "����");
	set("long", "�����м�һ���ˣ�������֥�ɰ��塣��«�������굤����׭����ǧ���١�
����Ǭ�������ɣ�����������ɾ͡������ĺ������У�ɢ��ʮ���ݸ��С�
����������⣬��ʱ���»����ɡ���ͷ������������ϼ�֮�������١�\n");
        set("attitude", "peaceful");
        set("combat_exp", 800000);
	set("daoxing", 1500000);

	create_family("��ׯ��", 2, "����");
	set("age", 80);
	set("per", 100);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
	set("class", "xian");
	set("rank_info/respect", "������");
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 800);
	set("mana", 800);
	set("mana_factor", 50);
	
	set_skill("spells", 120);
	set_skill("taiyi", 120);
	set_skill("force",120);
	set_skill("zhenyuan-force",120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("baguazhen", 120);
	set_skill("unarmed", 120);
	set_skill("wuxing-quan", 120);
	set_skill("staff",110);
	set_skill("fumo-zhang",120);

	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("dodge", "baguazhen");
	map_skill("unarmed", "wuxing-quan");
	map_skill("staff", "fumo-zhang");
	map_skill("parry", "fumo-zhang");

        set("inquiry", ([
		"����"     : "��û�����⣬ȥ�����ϸ��ǰɣ�\n",
		"����"     : "��û�����⣬ȥ������»�ǰɣ�\n",
                "name"     : "�Ϸ�������Ҳ��\n",
                "here"     : "���������ɵ�Ҳ��\n",
                "����"     : "�������¨�ӣ�˭Ҫ�������壡\n",
                "Χ��"     : "��Χ�嶼��֪����\n",
                "��ź"     : (: ask_me :),
        ]));

	setup();
/*
	carry_object("/d/obj/cloth/baipao")->wear();	
	carry_object("/d/penglai/npc/obj/guai")->wield();
*/
    // mudring Dec/02/2002
    if (clonep())
    {
        object ob = unew(BINGQI_D("staff") + "/dragonstaff");
        if (!ob) ob = new(BINGQI_D("staff") + "/shugan");
        ob->move(this_object());
        ob->wield();
        carry_object("/d/obj/cloth/baipao")->wear();    
    }
	
	// mon 7/19/98
        // first fruit generated after the xing refresh
        // for a while.
        set("time", 0);
        call_out("reg", 1500+random(500));

}

string ask_me()
{
//      object ob;
	        
	if((int)this_player()->query("combat_exp") < 50000 )
		return "û���Ϸ������������Ժ���˵�ɣ�\n";

	// added by snowcat on 6/22/1997
	if (this_object()->is_fighting())
		return "û���Ϸ����������Ժ���˵�ɣ�\n";

	if ( present("bi ou", this_player()) )
		return "�ԣ��ԣ��ԣ��ֵĶ������ˣ�\n";

        if ( present("bi ou", environment()) )
		return "�ǲ�����һ�����������˵��\n";

        if (query("last_winner") == this_player()->query("id") &&
            random(5)) {
                set("noask",1);
            	call_out("ref", 20);
                return "���ɣ����ɣ���Ҳû�ˣ�\n";
        }        
                                    
	if(query("time") <1 || query("noask"))
		return "���ɣ����ɣ���Ҳû�ˣ�\n";

		say("����˵�����ǵ�Ҫ���㹻��������ˣ���������ɣ�\n");
		this_player()->set_temp("shouxing_fight", 1);
		return ("�ٺ٣�\n");
}


int accept_fight(object who)
{
  	object me;
 	me = this_object();
  	if (!who->query_temp("shouxing_fight")){
		command("say ���򲻴�û���Ϸ�����������\n");
    		return 0;
	}
	// added by snowcat on 6/22/1997
	if (me->is_fighting()){
		command("say ���򲻴�!\n");
		return 0;
	}
	say("����Ц������ͷ�ӻ��˼�ǧ�꣬˭Ҳ���£�\n");
	me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

  	who->set_temp("shouxing_fight",0);
  	remove_call_out("check_fight");
  	call_out("check_fight", 1, me, who);
  	return 1;
}

void player_win (object me, object who)
{	
	object obj;
	// added by snowcat on 6/22/1997
	if (me->query("time")<=0)
	        return;
	obj = new("/d/obj/drug/biou");
	command("sigh");	
	say("����̾��һ��������ʹ��ˣ������������ǲ��ã�\n");
	say("����˵����������Ӣ�۱������ұ����ӣ�\n");
	obj->move(who);
        me->add("time", -1);
        message_vision("���Ƕ�$N����Ц������з�����������Ա����ؾ߱�źһö��Ц�ɣ�\n", who);
        me->set("last_winner",who->query("id"));
	call_out("reg", 500+random(500));
}
int ref()
{
	object me, obj;
	me=this_object();
	me->set("noask", 0);
}	
int reg()
{
	object me, obj;
	me=this_object();
	me->set("time", 1);
//add a weapon in case anyone took it.
	if(!me->query_temp("weapon")){
		obj=new("/d/obj/weapon/staff/shugan");
		obj->move(me);
		command("wield all");
	}
	return 1;
}
void player_lose (object me, object who)
{
  	string msg;
  	msg = RANK_D->query_respect(who);
	
	command("jump");
	say("���ǹ�����Ц��"+msg+"ĪҪ�����ˣ���ȥ�ú�����ɣ����շ����\n");
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
	
	// changed by snowcat on 6/24/1997
	// bug abuse: player can exert recover when fight stops,
	//if ((my_kee*100/my_max_kee) <=(whos_kee*100/whos_max_kee) )
	//      player_win (me, who);
	//else player_lose (me, who);
	if ((my_kee*100/my_max_kee) <= 50)
		player_win (me, who);
	else if ((whos_kee*100/whos_max_kee) <= 50)
		player_lose (me, who);

}

void die()
{

        if( environment() ) {
        message("sound", "\n\nֻ��һ�����������ǻ���һ���׹�������ֱ���ȥ������\n\n
��������˹���Ц�˼���������\n\n", environment());
        }

        destruct(this_object());
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="��ׯ��" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			command("say ���ҵ������ҵ���\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			command("say �Ǻǣ���" + ob->query("family/master_name") + "��ͷ��ͽ�ܣ����ҾͲ������ˡ�\n");
			command("recruit " + ob->query("id") );
		}
		else 
		{
			if( ob->query_skill("taiyi", 1) >= 80 )
			{
				command("say �ã��г�Ϣ�����ͽ���������ˡ�\n");
				command("recruit " + ob->query("id") );
			}
			else
			{
				command("say �����ɼ�����ɷ����㻹�����ⷽ���¿๦��\n");
			}
		}
	}

	else
	{
		command("say �ã������㻹�����Ұ���������һЩ���ŵĹ���ɡ�\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}


�