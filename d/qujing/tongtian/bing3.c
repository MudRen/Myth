// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���涳�ý��ʵʵ������һ����Ѿ������߳�һ�������ı�
����Ҳ�д���˻������µĺۼ���������ش������ϣ��̹ǵ�
���䡣

LONG);

  set("exits", ([
        "west"   : __DIR__"hexi4",
        "east"   : __DIR__"bing4",
        "north"   : __DIR__"bing1",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(3)+1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  object where = this_object ();
  object who = this_player ();

  call_out ("cracking",random(20)+5,where);
  call_out ("testing",random(30)+30,who,where);
}

void cracking (object where)
{
  tell_room (where, "�������ǵ�һ�����졣\n");
}

int test_player (object who)
{
  string *names;
  string name;

  if (! who)
    return 0;

  names = who->query_temp("apply/name");
  if (! names)
    return 0;

  if (sizeof(names) < 1)
    return 0;

  name = names[0];

  if (name != "Сͯ")
    return 0;

  if (present ("bishui zhou",who))
    return 2;
  return 1;    
}

void testing (object who, object where)
{
  int status = test_player(who);

  if (status==0)
  {
    tell_room (where, "���������졣\n");
    return;
  }

  if (environment (who) != where)
    return;

  message_vision ("�������ѿ�һ���ѷ죬$Nһ��������������ˤ��ˮ�У�\n",who);
  if (status == 1)
  {
    message_vision ("���˸�������æ��$N����һ���ϳ���ˮ��\n",who);
    who->unconcious();
    return;
  }
  who->move(__DIR__"hedi");
}

