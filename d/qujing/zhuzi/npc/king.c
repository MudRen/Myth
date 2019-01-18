// by snowcat 11/6/1997

inherit NPC;

int test_player (object me);
object copy_yao(object ob);

void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "���Ϲ��Ĺ�����ͷ�����ڣ���ִ�Ͻ��ȡ�\n");
  set("title", "���Ϲ�");
  set("gender", "����");
  set("rank_info/respect", "����");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
        "name":   "�������Ϲ�����Ҳ���������岻�ʣ���ҽ������",
        "����":   "��֮��Ψ��ʥ�����ѱ������ӡ�",
        "��ʥ��": "��ʥ�������������ӡ�",
        "����":   (: test_player :),
        "��":     (: test_player :),
        "ҽ":     (: test_player :),
        "ҽ��":   (: test_player :),
        "ҽ��":   (: test_player :),
        "ҩ":     (: test_player :),
        "��ҩ":   (: test_player :),
      ]));

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void throw_player (object who)
{
  object me = this_object();

  message_vision ("$N����һ�����Ϳͣ�\n", me, who);
  message_vision ("��λ̫������������˵����$N���ߡ�\n", who);
  who->move("/d/qujing/zhuzi/hugong1");
  call_out ("in_river",1,who);
  me->start_busy(1,1);
}

void in_river (object who)
{
  message_vision ("$N���������������Լ������ڱ���Ļ�����ˮ�\n", who);
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$N˵������λ"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<10000)
  {
    inform_player (msg+"���в���������ӹҽҲ��\n",who);
    call_out("throw_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/zhuzi") == "done" ||
      who->query_temp("obstacle/zhuzi_cured"))
  {
    inform_player (msg+"����л��л�����ٰݶ��ף�\n",who);
    return 1;
  }  

  if (this_object()->query_temp("cured"))
  {
    inform_player (msg+"���ض��ǣ����ѿ�����\n",who);
    return 1;
  }  

  inform_player (msg+"���ɷ�Ϊ��Ѱ���ڽ𵤣�\n",who);
  who->set_temp("obstacle/zhuzi_asked",1);
  call_out ("wait_player",300,who);
  return 1;
}

void wait_player (object who)
{
  if (who)
    who->set_temp("obstacle/zhuzi_waited",1);
}

int accept_object (object who, object ob)
{
  object me = this_object();
  object ob2;
  string msg = "$N˵������λ"+RANK_D->query_respect(who);

  if (ob->query("id") != "yao")
  {
    inform_player (msg+"������ӵ�н�ɽ��𢣬�������С���ݴ����ģ�\n",who);
    call_out("throw_player",1,who);
    call_out("destroy_object",1,ob);
    return 1;    
  }

  if (who->query("combat_exp")<10000)
  {
    inform_player (msg+"���в��������Ǽ�ҩҲ��\n",who);
    call_out("throw_player",1,who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (who->query("obstacle/zhuzi") == "done" ||
      who->query_temp("obstacle/zhuzi_cured"))
  {
    inform_player (msg+"����л��л�����ٰݶ��ף�\n",who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (this_object()->query_temp("cured"))
  {
    inform_player (msg+"���ض��ǣ����ѿ�����\n",who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (! who->query_temp("obstacle/zhuzi_waited"))
  {
    inform_player (msg+"���ڽ��˹���֮ҩ����Ѱ�ſɵã���ҩ�����м٣�\n",who);
    call_out("delayed_vision",1,"$N��ҩ���Ա���Ͱ��һ�ӡ�\n",me);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  message_vision ("$N����ҩ����$n������л��\n",me,who);
  call_out("delayed_vision",3,
           "���м�λ��Ů�������ź���$N��ҩ���޸�ˮ���¡�\n",me); 
  ob2 = copy_yao(ob);
  call_out("eat_drug",1,me,ob2,who);
  return 1;
}

void delayed_vision (string msg, object me)
{
  message_vision (msg,me);  
}

void destroy_object (object ob)
{
  destruct (ob);
}

void eat_drug (object me, object ob, object who)
{
  int i = who->query_temp("obstacle/zhuzi_given");

  if (! ob->query_temp("is_ready"))
  {
    message_vision ("$NͻȻһ���Ӹ�ʹ��������������������\n",me,who);
    message_vision ("$N˵������ҩ����ҩҲ��\n",me,who);
    call_out("throw_player",1,who);
    destruct (ob);
    return;
  }
  if (i < 2)
  {
    message_vision ("���꣬$N�������ؿ�̩����Ѫ����һЩ�ˡ�\n",me);
    me->command_function("thank "+who->query("id"));
  }
  else
  {
    message_vision ("$N�����³�һЩ�����������������ɫҲ�ָ��ˡ�\n",me);
    message_vision ("\n$N��$n˵��������������ɽ�����˳�л������\n",me,who);
    me->set_temp("cured",1);
    who->set_temp("obstacle/zhuzi_cured",1);
    call_out("say_more",5,me,who);
  }
  who->set_temp("obstacle/zhuzi_given",i+1);
  destruct (ob);
}

void say_more (object me, object who)
{
  message_vision ("\n$N˵���������³��Ļ��������֮����Ҳ��\n",me);
  message_vision ("$N��˵���������ˣ���������ҹ��˼���ʥ����\n",me);
  call_out("say_more2",3,me,who);
}

void say_more2 (object me, object who)
{
  message_vision ("\n$N�����$n˵�������˿ɷ����޾Ƚ�ʥ����ع���\n",me,who);
}

// by wuliao.
// since the give command destruct the object quickly, we need get a new object
// with the same attributes
object copy_yao ( object me )
{
	object who = new ( "/d/qujing/zhuzi/obj/yao.c");

	who -> set("name", me->query("name"));
	who -> set_temp("is_ready", me->query_temp("is_ready") );
	who -> move(this_object());
	
	return who;
}�