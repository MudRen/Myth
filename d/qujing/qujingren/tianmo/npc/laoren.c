// blacksh 01/19/99

// �������˵�����:	��ҿ��������跨��(��ħ��),ֻ����������ſ���ץ
//			ȡ����,��Ҫ�����Ĵ��۾����Ժ��ܲμ�ȡ��
//			����´�Ҫ�μ�ȡ���Ļ�,����Ҫ�ɹ��ĳԵ�һ��ȡ����
//			ȡ���˱�ץ���Զ����͵����˾�ס�ĵط�,OBSTACL_D
//			��last_env��ŵ���ȡ���˱�ץ�Ļ���,�����Ҿȳ�
//			ȡ���˺�Ϳ���ask laoren  about back,���ص�ԭ��
//			�ĵط�.

//			�����ʹ����ħ��ץסȡ�����˺�,ȡ�����Զ����͵�
//			������,�������������˾Ϳ�����ȡ����,����ط���
//			���˿�ʼ�ڵĵط�����ͬ.���Ҫ��ȡ���˾�Ҫ��7��
//			�ؿ�,�ﵽ����������.

//			��������24Сʱ��û�оȳ�ȡ����,ȡ����ʧ��.
//			ȡ���˱������߿�,һ���������������,����������
//			��ħ������.



inherit NPC;


int ask_fabao();
int do_back();

void create()
{
  set_name("��������", ({"zhenglong laoren", "laoren"}));
  set("long", "��˵����ǰ��һ���ǳ�������ʳ������,���������һ��...\n");
  set("gender", "����");
  set("age", 5000);
  set("attitude", "peaceful");
  set("str",50);
  set("per",50);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 5000);
  set("max_force", 5000);
  set("force_factor", 500);
  set("max_mana", 5000);
  set("mana", 5000);
  set("mana_factor", 500);
  set("combat_exp", 2000000);
  set_skill("literate", 200);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 200);
  set_skill("jienan-zhi", 200);
  set_skill("dodge", 200);
  set_skill("lotusmove", 200);
  set_skill("parry", 200);
  set_skill("force", 200);
  set_skill("lotusforce", 200);
  set_skill("staff", 200);
  set_skill("lunhui-zhang", 200);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);


  set("inquiry", ([
    "�豦" : (: ask_fabao :),
    "jiebao" : (: ask_fabao :),
    "����" : "������ħ����Բ�ס��εĶ���,������",
    "����" : "������ħ����Բ�ס��εĶ���,������",
    "fabao": "������ħ����Բ�ס��εĶ���,������",
    "back" : (: do_back :),
    "��ȥ" : (: do_back :),
  ]) );

  setup();
}


void init ()
{
  add_action("do_kill", "kill");
  add_action("do_kill", "cast");
  add_action("do_kill", "ji");
  add_action("do_kill", "steal");
  add_action("do_accept","accept");
}


int ask_fabao()
{
  object me,who,ob;

  me=this_object();
  who=this_player();

  if (who->query("obstacle/qujing")=="ren")
    {
 	me->command_function("say ��豦�㲻���ʸ�");
	return 1;
    }

  if (who->query("combat_exp")<500000)
    {
 	me->command_function("say ��豦�㲻���ʸ�");
	return 1;
    }
    
  if (who->query("obstacle/no_qujing"))
    {
      if (time()-who->query("last_ask_fabao")<24*3600)
    	{  //ÿ��һ�����ֻ�ܽ�һ��
 		message_vision("$N��$n¶�������ε�����\n",me,who);
		me->command_function("shake")		;
		return 1;
    	}
    }	

  if (OBSTACLE_D->query("last_jie_id"))
    {
	ob=find_object("tianmo jian");
	if ( ! interactive( environment(ob) ))
          {
           OBSTACLE_D->back()    ;
		//����tianmo jian���Ը�,�����ҽ���������,�Ϳ�������ץ
		//ȡ����,����������ж�,��������������Զ�����.
	  }
        else
 	  {
	    me->command_function("say ������һ��,�Ѿ���������");
  	  }
	return 1;
    }

  me->command_function("say Ҫ����ҵķ���,����Ҫ����ħ����,�����ͬ��Ļ�,
accept");
  who->set_temp("can_accept",1);
  return 1;    

}

int do_accept()
{
  object me,who,ob;
  me=this_object();
  who=this_player();


  if (who->query_temp("can_accept"))
    {
      me->command_function("ok");
      message_vision("$N���ַ���$n��ͷ��,���������д�,һ�ɺ���ע��$n������\n"
		,me,who);
      who->delete_temp("can_accept");
      who->set("last_ask_fabao",time());
      who->set("obstacle/no_qujing",1);
	//ȡ�������˲�����ȡ��,���ǳɹ��Ե�һ��ȡ����
      ob=new("/d/qujing/qujingren/tianmo/obj/tianmojian");
      ob->move(who);	      
      OBSTACLE_D->delete("open_door");
      OBSTACLE_D->set("last_jie_id",who->query("id")); 
      OBSTACLE_D->back_fabao();
	//һ����ҽ��ܽ�һ��Сʱ,һ��Сʱ��û��ץ��ȡ���˾��ջط���.
 	//��ֹһ����ҽ��߷���,�԰�����һ���˹���
      return 1;
    }
  return 1;
 
}

int do_back()
{
  object me,who,ob,qjr,where;

  me=this_object();
  who=this_player();

  if (who->query("obstacle/qujing")=="ren")
    {
      if (qjr=present("qujing ren",environment(me)))
        {
	me->command_function("say ��С��,�б���,��������������");
        where=load_object(OBSTACLE_D->query("last_env"));
        message_vision("$N��$n��Ȼ��һ����������ס...������ʲô����ʧ��",
		qjr,who);
	qjr->move(where);
	who->move(where);
	OBSTACLE_D->set("where_qujingren",OBSTACLE_D->query("last_env"));
	OBSTACLE_D->delete("last_env");
	OBSTACLE_D->delete("open_door");
	destruct(me);
	return 1;
  	}
    }
  return 1;
}

int do_kill()
{
  object me=this_object();

  me->command_function("say ������ǰ......");
  me->command_function("heng");
  this_player()->start_busy(50);
  return 1;

}


void die()
{
  if (environment())
    message("sound", "\n\n��������΢΢һЦ��\n\n", environment());

  set("eff_kee", 5000);
  set("eff_gin", 5000);
  set("eff_sen", 5000);
  set("kee", 5000);
  set("gin", 5000);
  set("sen", 5000);
  set("force", 5000);
  set("mana", 5000);
}

void unconcious()
{
  die ();
}



