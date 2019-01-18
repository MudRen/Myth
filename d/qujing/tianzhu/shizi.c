// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ʮ�ֲֽ�¥");
  set ("long", @LONG

���������ù��ĳ�����ʮ�ֽֿڣ�������������ʮ�����֣���
����һ��컭�̵�������¥��һ��Ⱥ�˼��ڲ�¥���ܣ���ͷ��
���˷ܵ�������ʲô��

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao56",
        "west"   : __DIR__"jiedao53",
        "north"   : __DIR__"jiedao45",
        "south"   : __DIR__"jiedao65",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 5,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  object who = this_player();
  object king = present("guo wang",this_object());

  if (! who)
    return;

  if (! interactive (who))
    return;

  if (king)
    return;

  if (who->query("combat_exp")<10000)
    return;
//  if (who->query("obstacle/tianzhu")=="done")
//    return;

  message_vision ("���ǽ�ͷ�Ӷ�������������ʲô��\n",who);
  remove_call_out ("noicing");
  call_out ("noicing",random(10)+5,who);
}

void noicing (object who)
{
  object where = this_object ();
  object king = present("guo wang",this_object());

  if (king)
    return;

  if (! who ||
      environment (who) != where)
    return;
  if (where->query("has_thrown"))
  {
    message_vision ("��Ⱥ��ߴߴ�������ۣ���˵���������һ·�͡�\n",who);
    message_vision ("������˵����Ҳ��֪�����˺�����Ҳ��\n",who);
    return;
  }
  message_vision ("��¥�����˸ߺ�������������ϣ���ף����ء�\n",who);
  remove_call_out ("preparing");
  call_out ("preparing",random(10)+10,who);
}

void preparing (object who)
{
  object where = this_object ();
  object king = present("guo wang",this_object());

  if (king)
    return;

  if (! who ||
      environment (who) != where)
    return;
  if (where->query("has_thrown"))
  {
    return;
  }
  message_vision ("��¥�������ָߺ��������ٴ�����Ů����\n",who);
  message_vision ("�����������͸����ź���������Ҳ��������Ҳ��\n",who);
  remove_call_out ("throwing");
  call_out ("throwing",random(10)+10,who);
}

void throwing (object who)
{
  object where = this_object ();
  object king = present("guo wang",this_object());

  if (king)
    return;

  if (! who &&
      environment (who) != where)
    return;
  if (where->query("has_thrown"))
  {
    return;
  }
  message_vision ("һֻ���������ž������$N��ͷ�ϣ�\n",who);
  if (who->query("gender") == "Ů��")
    message_vision ("�����Ǹߺ���Ů����Ů����\n",who);
  else
    message_vision ("�����Ǹߺ��������ˣ������ˣ�\n",who);

  where->set("has_thrown",1);
  call_out ("reset_thrown",1200);
  remove_call_out ("leaving");
  call_out ("leaving",random(10)+10,who);
}

void reset_thrown ()
{
  this_object()->set("has_thrown",0);
}

void leaving (object who)
{
  object where = this_object ();

  if (! who &&
      environment (who) != where)
    return;
  message_vision ("һƬߺ�����У���Ⱥ����һ�������������˹�����\n",who);
  message_vision ("������$N���һЦ������˵��ȥ������Ҳ��\n",who);
  message_vision ("һȺ�Źٹ�Ů��ӵ�����κ�����$N����ȥ��\n",who);
  who->move(__DIR__"jiedao45");
  who->move(__DIR__"wumen");
  who->move(__DIR__"zhaoyang");
  who->move(__DIR__"jinluan");
  message_vision ("$N���κ����������˹�����\n",who);
  message_vision ("�����Թ������˸����������������ȥ��\n",who);
  who->set_temp("obstacle/tianzhu_thrown",1);
}
