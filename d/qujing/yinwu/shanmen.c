// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ��֮����һ������꣬�������죬�ұ�����һʯ�š�ֻ����
ʯ�Ž��գ�������һ����ʯ�壬ʯ�������С�����ɽ��������
�����������֡�

LONG);

  set("exits", ([
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_break","break");
}

int do_break (string arg)
{
  object tudi;
  object who = this_player();

  if (! arg || (arg!= "door" && arg!= "men"))
    return notify_fail ("��Ҫ��ʲô��\n");

  message_vision ("$N����������һ��������ȥ��\n",who);
  message_vision ("\nһ����ʯ���죬����$N��ͷ�ϣ�\n",who);
  who->unconcious();    
  if (who->query("combat_exp") < 10000 ||
      random(4))
  {
    return 1;
  }
  if (present("tu di",this_object()))
    return 1;
  tudi = new (__DIR__"npc/tudi");
  tudi->move(this_object());
  tudi->command_function("hi");
  return 1;
}
