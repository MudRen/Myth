// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("����", ({"guo wang", "king" }));
  set("title","�����");
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
  set("combat_exp", 220000);
  set("daoxing", 150000);

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
  set("eff_dx",15000);
  set("nkgain",110);
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void check_princess(object me);

void init()
{
  ::init();
  check_princess(this_object());
}

int accept_object (object who, object ob)
{
  object me = this_object();
  object room = environment(me);

  if (room->query("short")!="��ظ�")
    return 0;

  if (ob->query("id")=="mi xin" &&
      who->query_temp("obstacle/baoxiang")=="got_letter")
  {
    remove_call_out("read_letter");
    call_out("read_letter",3,me,who,ob);
    return 1;
  }
  return 0;
}

void read_letter (object me, object who, object ob)
{
  destruct (ob);
  reset_eval_cost();
  // first time get letter from player
  if (who->query("obstacle/baoxiang")=="got_letter")
  {
    message_vision("$N�������ţ�����������¡�\n",me);
    message_vision("$N����������ң�������ǿ��ռΪ�ޣ�����ʮ����֮�ã�\n\n",me);
    message_vision("�˿��������ᣬ�������飬����һƬ������\n",me);
  }
  // already given letter before
  else
  {
    message_vision("$N��$n������λ"+RANK_D->query_respect(who)+
                   "�������������̹��˽�������౨��\n",me,who);
  }
  remove_call_out("send_to_fight");
  call_out("send_to_fight",3,me,who);
}

void send_to_fight (object me, object who)
{
  object ling = new ("/d/qujing/baoxiang/obj/ling");
  ling->move(who);
  message_vision("$N����˵������$n�˱��콫�������׽ɱ��ħ�����Ұٻ�������\n\n",
                 me,who);
  message_vision("�Ա����о�������ǰ�ݸ�$nһ֧�����ơ�\n",me,who);
  who->set("obstacle/baoxiang","given_letter");
  who->set_temp("obstacle/baoxiang","given_letter");
  who->save();
}

void check_princess(object me)
{
  object room = environment(me);
  object baihua = present("baihua xiu",room);
  object who;
  object ling;

  reset_eval_cost();
  if (room->query("short")!="��ظ�")
    return;
  if (baihua == 0)
    return;

  if (baihua->query("leader")==0)
    return;
  who = present(baihua->query("leader"),room);
  if (who == 0)
    return;
  if (who->query_temp("obstacle/baoxiang")!="given_letter")
    return;
  ling = present ("junling pai",who);
  if (ling == 0)
    return;
  
  baihua->set_leader(0);
  baihua->set_temp("no_return",0);
  remove_call_out ("cry_princess");
  call_out ("cry_princess",2,me,baihua);
  remove_call_out ("announce_success");
  call_out ("announce_success",4,me,who);
}

void cry_princess (object me, object baihua)
{
  message_vision("$N����$nһ㶣�Ȼ�������ݺ�ؽ�$n����ȥ��\n",me,baihua);
}

void announce_success (object me, object who)
{//disabled announce and reward...
  int i;
  who->add("obstacle/number",1);
  who->set("obstacle/baoxiang","done");
  who->set_temp("obstacle/baoxiang","done");
  i = random(800);
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"�˱��콫���汦����׽ɱ��ħ����Ȱٻ�������");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

�
