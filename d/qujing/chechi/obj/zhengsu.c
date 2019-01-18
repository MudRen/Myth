// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("����", ({"zheng su", "su"}));
  set_weight(1500);
  set("long", "һ�鹩��������������֡�\n");
  set("unit", "��");
  set("value", 140);
}

void init()
{
  add_action ("do_eat","eat");
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object yuanshi1 = present("yuanshi",where);
  object lingbao1 = present("lingbao",where);
  object taishang1 = present("taishang",where);
  object yuanshi2 = present("yuanshi 2",where);
  object lingbao2 = present("lingbao 2",where);
  object taishang2 = present("taishang 2",where);
  object yuanshi3 = present("yuanshi",who);
  object lingbao3 = present("lingbao",who);
  object taishang3 = present("taishang",who);
  object ob;

  if (! arg)
    return 0;

  ob = present(arg,who);
  if (! ob)
    ob = present(arg,where);
  if (ob != me)
    return 0;

  who->set("food",who->max_food_capacity());

  if (! where || where->query("short")!="�����")
  {
    message_vision ("$N��$n������ȥ��\n",who,me);
    destruct(me);
    return 1;     
  }
  // not valid sanqing
  if (! yuanshi1 || ! lingbao1 || ! taishang1)
  {
    where->daoshi_appear(who);
    message_vision ("$N������ʳ�ؽ�$n������ȥ��\n",who,me);
    destruct(me);
    return 1;     
  }   
  // too many sheng xiangs
  if (yuanshi2 || lingbao2 || taishang2)
  {
    where->daoshi_appear(who);
    message_vision ("$N���̻��ʵؽ�$n������ȥ��\n",who,me);
    destruct(me);
    return 1;     
  }   
  // haven't thrown sheng xiang away
  if (yuanshi3 || lingbao3 || taishang3)
  {
    where->daoshi_appear(who);
    message_vision ("$N������һ�㽫$n������ȥ��\n",who,me);
    destruct(me);
    return 1;     
  }   
  // player hasn't become one of sanqing
  if (who!=yuanshi1 && who!=lingbao1 && who!=taishang1)
  {
    where->daoshi_appear(who);
    message_vision ("$N��������һ�㽫$n������ȥ��\n",who,me);
    destruct(me);
    return 1;     
  }   
  // player is too weak to solve the quest
  if (who->query("combat_exp")<50000)
  {
    where->daoshi_appear(who);
    message_vision ("$N����ææ�ؽ�$n������ȥ��\n",who,me);
    destruct(me);
    return 1;     
  }   
  if (! who->query("obstacle/chechi"))
    who->set("obstacle/chechi","eaten");
  who->set_temp("obstacle/chechi","eaten");
  message_vision ("$Nһ�������ؽ�$n������ȥ��\n",who,me);
  where->daotong_appear(who);
  destruct(me);
  return 1;     
}
