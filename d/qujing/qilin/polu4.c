// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

��·������խ��ɽɫãã�������죬���Ϸ�����۷����ռ�أ���
ס��ǣ���ͷ��������·������ʯ���׸��ʣ�������һ�����ڽ���
·������

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"polu3",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N����������ȥ��\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 50)
  {
    message_vision ("$N��һ�����˴�ʯ����һ������������\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-50);
  who->move(__DIR__"shan11");
  return 1;
}
