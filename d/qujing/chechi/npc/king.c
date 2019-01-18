// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("����", ({"guo wang", "king" }));
  set("title","���ٹ�");
  set("gender", "����");
  set("rank_info/respect", "����");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 50);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 260000);
  set("daoxing", 100000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("seashentong", 50);
  set_skill("dragonforce", 50);
  set_skill("dragonstep", 50);
  set_skill("dragonfight", 50);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("spells", "seashentong");
  set("eff_dx",30000);
  set("nkgain",180);
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init()
{
  call_out("follow_player",2,this_object(),this_player());
}

int follow_player (object me, object who)
{
  object where = environment (me);
  object yangli = present("yangli",where);
  object huli = present("huli",where);
  object luli = present("luli",where);

  me->set_temp("no_return",1);
  if (where->query("short") != "���ǵ�")
    return 1;
  if (! yangli || ! huli || ! luli)
    return 1;
  if (! who)
    return 1;
  if (who->query("obstacle/chechi")=="done")
    return 1;
  if (who->query_temp("obstacle/chechi")!="eaten")
    return 1;
  if (environment(who) != where)
    return 1;
  if (me->query_temp("follow")==who->query("id"))
    return 1;
  message_vision ("\n��������������λ��ʦ���ˣ���\n",who);
  yangli->set_leader(me);
  huli->set_leader(me);
  luli->set_leader(me);
  message_vision ("\n�����ɴ���ǰȥ�����ڹ������£�����˵��ʲô��\n\n",me);

  remove_call_out("continue_follow");
  call_out("continue_follow",4,me,who);
  remove_call_out("continue_following");
  call_out("continue_following",8,me,who);
  remove_call_out("following_player");
  call_out("following_player",12,me,who);
  return 1;
}

int continue_follow (object me, object who)
{
  message_vision ("$N�Ծ��ذ���һ����\n",me);
  message_vision ("$Nŭ����������ͽ��������ƭ��ʦ����\n\n",me);
  if (who && environment(me)==environment(who))
  {
    message_vision ("$N�������ȡ���һ�����¡�\n\n",who);
    who->start_busy (9,10);
  }
  return 1;
}

int continue_following (object me, object who)
{
  object where = environment (me);
  object taijian = present ("tai jian",where);

  if (taijian)
    message_vision ("̫�����ȥ���������\n",me);
  message_vision ("$N����һ�룬΢΢���˵�ͷ��\n\n",me);
  return 1;
}

int following_player (object me, object who)
{
  object where = environment (me);
  object taijian = present ("tai jian",where);

  if (where->query("short") != "���ǵ�")
    return 1;
  if (! who)
    return 1;
  if (who->query("obstacle/chechi")=="done")
    return 1;
  if (who->query_temp("obstacle/chechi")!="eaten")
    return 1;
  if (environment(who) != where)
    return 1;
  if (me->query_temp("follow")==who->query("id"))
    return 1;

  if (taijian)
  {
    message_vision ("$N����ǰ������������$nһ���ж���\n\n",taijian,who);
    taijian->set_temp("no_return",1);
    taijian->set_leader(who);
  }
  message_vision ("$N������$n˵����������Զ���ɿͣ��Ҳ���������ʦһ�ȡ�\n",
                  me,who);
  message_vision ("\n$N�ֵ����������ǻ��ն��ǰ����������\n",me);
  message_vision ("$N������ʼ����$nһ���ж���\n",me,who);
  who->interrupt_me(who,"");
  me->set_temp("follow",who->query("id"));
  me->set_leader(who);
  who->set_temp("obstacle/chechi","seen_king");
  return 1;
}

void announce_success(object who)
{//disabled announce and reward...
  int i;

  if (who->query("obstacle/chechi") == "done")
  {
    tell_object (who,"���Ѿ�������һ�أ�ʲô���ò����ˣ�\n");
    return;
  }  

  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/chechi","done");
  who->add("daoxing",i+5000);
  command("chat "+who->query("name")+"���ٹ�ʩչʥ�֣�����������");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(5)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
  command("follow none");
}
�
