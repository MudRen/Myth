// rewritten by snowcat.c 4/4/1997
// niuer.c
#define NAME "ţ������"

inherit NPC;

int is_busy;
int is_empty;

void create()
{
  set_name(NAME, ({"niuer","xiansheng","daoshi"}));
  set("gender", "����" );
  set("age", 53);
  set("title", "��������");
  set("long", "ţ��������ţħ���ĵܵܡ�������һ��ϲ�����˽���\nţ����������ϲ������������������");
  set("class","taoist");
  set("combat_exp", 500000);
  set("daoxing", 800000);

  set("attitude", "peaceful");
  set_skill("unarmed", 90);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("spells",80);
  set("per", 25);
  set("max_kee", 600);
  set("max_gin", 200);
  set("max_sen", 400);
  set("force", 500);
  set("max_force", 500);
  set("inquiry", ([
        "name": "����ţħ���ĵܵܣ����˽�������������\n",
        "��������": "���⣬���⣬����ʱ�򳣳���һЩ���Ӳ������ë����\n",
        "����": "�����ͣ����Ӵ󣬶���ʹ�Ҷ�������һ�ԡ�\n",
      ]));
  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  is_busy = 0;
  is_empty = 0;
}

void return_object (object who, object ob, string id, int amount)
{
  if (! ob)
  { // money is normally destroyed when given to NPC!
    if (id == "thousand-cash")
    {
      ob = new("/obj/money/thousand-cash");
      ob->set_amount(amount/100000);
    }
    else if (id == "gold")
    {
      ob = new("/obj/money/gold");
      ob->set_amount(amount/10000);
    } 
    else if (id == "silver")
    {
      ob = new("/obj/money/silver");
      ob->set_amount(amount/100);
    } 
    else if (id == "coin")
    {
      ob = new("/obj/money/coin");
      ob->set_amount(amount);
    } 
    
    if (ob)
    {
      ob->move(who);
      tell_object(who,NAME+"��һЩ"+ob->query("name")+"�����㡣\n");
    }
  }
  else
    command("give "+who->query("id")+" "+id);  
}

int accept_object (object who, object ob)
{
  object queen;
  string msg, id;
  int amount;
  msg = NAME+"���ֵ�����λ"+RANK_D->query_respect(who);

  amount = ob->value(); 
  id = ob->query("money_id");
  if (! id)
  {
    id = ob->query("id");
    amount = 1;
    say(msg+"���������л��л�����ز�������\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }

  if (who->query("obstacle/nuerguo") == "done")
  {
    queen = new (__DIR__"queen");
    queen->refuse_player (who);
    destruct (queen);
    say(msg+"���ȡ���˵��Ҳ�ǡ�\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "marriage")
  {
    say(msg+"������ȥ�������ɡ�\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "company")
  {
    say(msg+"������ȥ�������ɡ�\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") != "stomachache")
  {
    say(msg+"����ûʲôë����\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }
  
  if ( ob->value() < 30000) 
  {
    say(msg+"���ȡ�������������ǲ��װɡ�\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (is_busy)
  {
    say(msg+"����Բ����Ҳ�����æ���β���\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  
  if (is_empty)
  {
    say(msg+"���Բ����β���Ȫˮ�����ˣ���һ��������ɡ�\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  say(msg+"����̫�����ˣ�����͸����β���\n");
  is_busy = 1;
  is_empty = 1;
  call_out("get_water",1,who);
  call_out("get_water",15,who);
  call_out("heal_stomach",30,who);
  who->start_busy(30,30); // will be reset when heal
  remove_call_out("reset_busy");
  call_out("reset_busy",30);
  remove_call_out("reset_empty");
  call_out("reset_empty",180);
  return 1;
}

void get_water (object who)
{
  if (who)
  {
    say ("\n"+NAME+"�����Ƶ��߹�ȥ��֨֨�¸µ�ҡ��һͰȪˮ��\n\n");
    call_out("pour_water",1,who);
  }
}

void pour_water (object who)
{
  if (who)
  {
    say (NAME+"����һֻ��ҩ�ѣ����������дʡ�\n");
    say ("ֻ������һ��Ͱˮ��Ȼȫ��������Сҩ���\n\n");
    call_out("feed_water",1,who);
    call_out("feed_water",2,who);
    call_out("feed_water",3,who);
  }
}

void feed_water (object who)
{
  if (who)
  {
    message_vision (NAME+"�����ҩ�ѣ���Ȫˮ�������$N�����\n",who);
    message_vision ("һ����������$N�����ڣ�$N�Ķ����ﶯ��һ�¡�\n",who);
  }
}

void heal_stomach (object who)
{
  int res;

  if (! who)
    return;

  if (random(10)==0)
  {
    message_vision ("\n$N�Ϳ��˼��£�����Ǻ��һЩ����ɫ��ˮ��\n",who);
    res = 1;
  }
  else
  {
    message_vision ("\n$N�����������죬��ȳ�ʲô����ʲô��û�ȳ�����\n",who);
    res = 0;
  }
  call_out("check_result",1,who,res);
}

void check_result (object who, int res)
{
  object queen;

  if (! who)
    return;

  if (res)
  {
    say (NAME+"����¶����΢Ц��������ҩ�Լ��ѣ��κ��ˡ�\n");
    queen = new (__DIR__"queen");
    queen->announce_success (who,"�κ��˸�ˮ��");
    destruct (queen);
  }
  else
  {
    say (NAME+"̾��һ�������ţ�û���κã�����������һ�Ρ�\n");
  }
  who->interrupt_me();
}

void reset_busy ()
{
  is_busy = 0;
}

void reset_empty ()
{
  is_empty = 0;
}
�