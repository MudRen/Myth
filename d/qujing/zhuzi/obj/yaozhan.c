// by snowcat 11/22/1997

inherit ITEM;

void create()
{
  set_name("��ҩյ", ({ "yin yaozhan","yaozhan","zhan"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(5);
  if( clonep() ){
    set_default_object(__FILE__);
  }  else {
    set("unit", "ֻ");
    set("long", "����һֻ�λ���ҩյ��\n");
    set("value", 1000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  add_action ("do_fill","fill");  
}

int do_fill (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object horse = present ("horse",where);

  if (! arg)
    return 0;

  if (present(arg, who) != me)
    return 0;

  if (! horse)
    return 0;  

  if (interactive(horse))
    return 0;

  message_vision ("$N����ҩյ����$n�Ķ�Ƥ���£����˼�����֭��\n",who,horse);
  me->set_temp("has_liquid",1);
  return 1;
}

// 0: not valid, 1: valid
int check_valid_drug (object yao, string name)
{
  if (yao->query_temp("is_invalid"))
    return 0;
  if ((name=="���" || name=="�Ͷ�" || name=="����") &&
      (! yao->query_temp("mixture/"+name)))
  {
    yao->set_temp("mixture/"+name,1);
  }
  else
  {
    yao->set_temp("is_invalid",1);
    return 0;
  }
  if (yao->query_temp("mixture/���") &&
      yao->query_temp("mixture/�Ͷ�") &&
      yao->query_temp("mixture/����"))
  {
    yao->set_temp("is_ready",1);
  }
  return 1;
}

void make_drug ()
{
  object me = this_object();
  object who = this_player();
  object yao1 = present("yao 1",me);
  object yao2 = present("yao 2",me);
  string name1, name2;

  if (! yao2)
    return;

  name1 = yao1->query("name");
  name2 = yao2->query("name");
  call_out ("display_message",1,who);
  yao1->set("name","ҩ");
  call_out("destruct_drug",1,yao1);
  if (! me->query_temp("has_liquid"))
  {
    yao2->set_temp("is_invalid",1);
    yao2->set("name","ҩ");
    yao2->set("unit","��");
    return;
  }
  if (name1=="ҩ")
  {
    yao2->set_temp("is_invalid",1);
    yao2->set("name","ҩ");
    yao2->set("unit","��");
    return;
  }
  if (name2!="ҩ")
    check_valid_drug (yao2,name2);
  check_valid_drug (yao2,name1);  
  yao2->set("name","ҩ");
  yao2->set("unit","��");
}

void display_message (object who)
{
  message_vision ("$N����ҩյ���ҩ�����һ�𣬽�����ȡ�\n",who);
}

void destruct_drug (object yao)
{
  destruct (yao);
}
