// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

��һ������ɽ�������촦���������ռ�ش�Զ������������������
ɽ�ڣ��ϱ߳ʹ�״������ɽ��ɽ�������������ͺͺ����ɫһƬ��
���չ�һ�㡣

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"yading",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N��������������ȥ��\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 50)
  {
    message_vision ("$N�������ˤ����̨�¡�\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-50);
  who->move(__DIR__"shan23");
  return 1;
}
