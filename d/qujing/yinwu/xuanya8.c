// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��ɽ���룬���ƴ�Ρ��ֻ�����ϰ���ƮƮ����ǰ��Ӱ��������
���ɰ�ǧǧ����ͷ���񼸸ɡ��Ĵ���ʯ���ף�ʹ���ĸв�����
�������Ծٲ���

LONG);

  set("exits", ([
        "northup"    : __DIR__"xuanya6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N�ֽŲ��÷ܲ������������ȥ��\n",who);
  if (who->query("combat_exp") < 10000 ||
      random(4))
  {
    message_vision ("\n��������һ����$Nʧ�ֻ���������\n",who);
    who->unconcious();    
  }
  else
    who->move(__DIR__"shanmen");
  return 1;
}
