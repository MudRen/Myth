// created by snowcat.c 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ����һ��ϸ�����Ѷ��£�����һϪɽ���ڽ�����ʯ���̿���
�򶫱��Ƶ�������ȥ������������һƽ̨����������һ����ɽ��
�羰����������ȴ��������ġ�

LONG);

  set("exits", ([
        "eastdown"    : __DIR__"jiandi",
        "westup"    : __DIR__"ling2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump ()
{
  object who = this_player();

  if (who->query("combat_exp") < 5000 ||
      ! present("huang qian",who))
  {
    message_vision ("$N������������һԾ��ȴ����߷���һ��������ȥ��\n",who);
    who->move(__DIR__"jiandi");
    who->unconcious();    
    return 1;
  }
  message_vision ("$N�����ľ��ص��һ����ವ�һ��Ծ�˹�ȥ��\n",who);
  who->move(__DIR__"jiankou2");
  return 1;
}
