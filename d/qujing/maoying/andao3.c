// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ƺ�ʲôҲ���������ֻ���ð�����ʪ���쬣�������
̽��ǰ���ĳ�·����

LONG);

  set("exits", ([
      ]));

  setup();
}

void init ()
{
  add_action ("do_go", "go");
}

int do_go (string dir)
{
  object who = this_player();

  if (! dir)
    return 0;

  if (dir == "east" ||
      dir == "west" ||
      dir == "south" ||
      dir == "north")
  {
    if (random(5))
    {
      message_vision ("$N�ںڰ��а��ײ����ʯǽ�ϡ�\n",who);
    }
    else
    {
      message_vision ("$N�ںڰ����ҵ�һ���ڣ����˳�ȥ��\n",who);
      who->move(__DIR__"shanpo3");
    }
    return 1;
  }
  return 0;
}



