// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������ľïʢ�ߴ�֦Ҷ���̰߰ס������(tree)�ĸ�
����潻����һ�𣬿���ȥʮ�����ء��紵�����ϣ�������һ
�����������졣

LONG);

  set("exits", ([
        "west"    : __DIR__"yang3",
        "northwest"    : __DIR__"yang2",
        "east"    : __DIR__"yang5",
      ]));
  set("item_desc", ([
       "tree" : "����֦������һ�𣬳���ͬһ�����ϡ�\n",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_turn","turn");
  add_action ("do_push","push");
}

int do_turn (string arg)
{
  object who = this_player();
  int times = who->query_temp("obstacle/biqiu_turns");

  if (! arg ||
      (arg != "left" &&
      arg != "right"))
    return notify_fail ("������ͷ��Ӭһ��Χ����ת��������\n");
 
  if (arg == "left")
  {
    message_vision ("$NΧ��������ת��һȦ��\n",who);
  }  
  if (arg == "right")
  {
    message_vision ("$NΧ��������ת��һȦ��\n",who);
  }  
  who->set_temp("obstacle/biqiu_turns",0);
  return 1;
}

int do_push (string arg)
{
  object who = this_player();

  if (! arg ||
      arg != "tree")
    return notify_fail ("�����������ʲô��\n");
 
  message_vision ("$N����ֽ�������һ�ơ�\n",who);
  who->set_temp("obstacle/biqiu_turns",0);
  return 1;
}
