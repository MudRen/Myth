// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// whitexiu.c

inherit NPC;
string ask_me();

void create()
{
        set_name("������ʿ", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "����" );
        set("age", 25);
        set("long", "һλ������������������ɫ�������ֵֹġ�\n");
        set("combat_exp", 100000);
        set("attitude", "peaceful");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("force", 50);
        set("per", 25);
        set("max_kee", 700);
        set("max_sen", 700);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 20);
	set("inquiry", ([
		"���»�"     : (: ask_me :),
	]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
string ask_me()
{
	if(this_player()->query("obstacle/guanyin")!="done"){
		this_player()->set_temp("obstacle/guanyin_ask","foyi");
		call_out("autokill",1,this_player(),this_object());
		return "�ߣ�����ô֪���ģ��������������ڣ�";
	}else{
		return "�ߣ�����ʲô�¡�";
	}	
}
void autokill (object me, object who)
{
  message_vision ("$n˵�գ���¶�׹⣬��$N�˹�����\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if ((ob)&&(ob->query_temp("obstacle/guanyin_yuanzhu"))&&(ob->query_temp("obstacle/guanyin_ask") == "foyi"))
  {
	ob->set_temp("obstacle/guanyin_xiushi",1);
	message_vision("$Nת������...���ˣ�һ�������Ե��ڵأ�����ԭ�Σ��������׻��߹֡�\n",me);
  }else{
	message_vision("$Nһ�������Ե��ڵأ�����ԭ�Σ��������׻��߹֡�\n\n",me);
  }
  message_vision("$N�������������������߶Ρ�\n\n",ob);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",1,me);
}
void destruct_me(object me)
{
	if(me)
	destruct(me);
}
void die()
{
  unconcious();
}
