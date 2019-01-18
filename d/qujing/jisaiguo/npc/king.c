inherit NPC;

void create()
{
       set_name("����������", ({"jisai guowang", "guowang", "king"}));
       set("gender", "����");
       set("age", 30);
        set("long", "������������������Ӣ����������ӡ�\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 25);
	set("str", 25);
       set("combat_exp", 15000);
  set("daoxing", 30000);

        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 75);
        set_skill("parry", 75);
	set_skill("force", 75);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 10);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 30);
        set("mana", 30);
setup();
	carry_object("/d/obj/cloth/longpao")->wear();
}


int accept_object(object me,object ob)
{       object who;
	me=this_object();
        who=this_player();

        if (ob->query("id")=="shu tie" ){
	if(who->query("obstacle/jisaiguo")=="done") {
		command("say "+RANK_D->query_respect(who)+ "������ȡ���˷𱦣����������ˣ�\n");
		call_out("destroy", 1, ob);
		return 1;
	}	
	if(who->query("obstacle/jisaiguo")=="allow") {
			command("say " +RANK_D->query_respect(who)+ "��û������\n");
                call_out("destroy", 1, ob);
                return 1;
	}	
	if( who->query_temp("obstacle/jisaiguo/letter")) {
		command("say ԭ����ˣ������޴���˽���µ�ɮ���ˡ�\n");
		command("say " +RANK_D->query_respect(who)+
"����ĺ����գ��������ްѷ�ȡ�أ��츣���ա�\n");
		who->set("obstacle/jisaiguo", "allow");
                call_out("destroy", 1, ob);
                return 1;
        }
	command("say ����֪���ˣ�����"+RANK_D->query_respect(who)+ "�����ˣ�\n");
        call_out("destroy", 1, ob);
	return 1;
	}

	if(ob->query("id")=="tooth") {
		if( !ob->query("asdfghj") ){
			command("say ʲô�������޲�Ҫ����\n");
			return 0;
			}
		if( who->query("obstacle/jisaiguo")=="done") {
			command("say ����" +RANK_D->query_respect(who)+ "�ˣ�ףһ·˳�硣\n");
			call_out("destroy", 1, ob);
			return 1;
			}
		call_out("announce_success", 3, me, who);
		call_out("destroy", 1, ob);
		return 1;
	}
	return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void announce_success(object me,object who)
{//disabled announce and reward...
    int i;
  who->add("obstacle/number",1);
  who->set("obstacle/jisaiguo","done");
  who->delete_temp("obstacle/jisaiguo");
  i = random(800);
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"����ȡ�ط������ӣ�Ϊ���������츣���������ĳ�Ҳ��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

�
