// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽʯ����֮������б���������������£�������������ˮ֮��
���ϣ���ˮ�������ˮ�еĴ�Сʯ�飬����һ�������������
���������������м���������

LONG);

  set("exits", ([
        "northup"    : __DIR__"xuanya7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_dive","dive");
}

int do_dive (string arg)
{
  object who = this_player ();

  message_vision ("$N��ˮ��һ��Ǳ����ȥ����\n",who);
  if (! who->query_temp("apply/name") ||
      who->query_temp("apply/name")[0] != "ˮ����")
  {
    message_vision ("\nֻ��$N����æ���ҵ����ϰ�����\n",who);    
  }
  else
    who->move(__DIR__"tianjing");
  return 1;
}
