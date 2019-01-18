// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

���䴦һ���޴�Ķ��ڣ������һ���ſ�Ѫ���ڡ�����ƻ�ͨ��
�з�����������Ʈ�����������Ϸ���һ����͹����д�š�����
ɽ��������������֡�

LONG);

  set("exits", ([ 
    "eastdown" : __DIR__"yading",
    "northeast" : __DIR__"dongnei",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  int to_die = who->query("combat_exp") < 4000;

  if (dir == "eastdown")
    return ::valid_leave (who,dir);

  if (who->query("combat_exp")>1000000 &&
      ! wizardp(who))
    return ::valid_leave (who,dir);

  switch (random(3))
  {
    case 0:
    {
      message_vision ("ͻȻ�����������⣬��ǧ������ӭ��������\n\n",who);
      message_vision ("$N��ǿ���˼������˵��ڵء�\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","��ǧ�����������ˡ�");
        who->die();
        who->save();
      }
      break;
    }
    case 1:
    {
      message_vision ("ͻȻ����ð���ɹ���ɫ���̣�����ǵع���������\n\n",who);
      message_vision ("$N��ǿ���˼������˵��ڵء�\n",who);
      who->unconcious();
      if (to_die && objectp(who))
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","����ɫ����Ѭ���ˡ�");
        who->die();
        who->save();
      }
      break;
    }
    case 2:
    {
      message_vision ("ͻȻ����ų�����ɳ����������յ��̽�������\n\n",who);
      message_vision ("$N��ǿ���˼������˵��ڵء�\n",who);
      who->unconcious();
      if (to_die && objectp(who))
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","������֮ɳ�����ˡ�");
        who->die();
        who->save();
      }
      break;
    }
  }  
  if (! to_die)
    call_out ("moving",1,who);
  //return notify_fail("��һ��������ת����\n");
  return 1;
}

void moving (object who)
{
  who->move(__DIR__"dongnei");        
}
