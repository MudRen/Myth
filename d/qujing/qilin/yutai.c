// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��̨");
  set ("long", @LONG

ɽ��·�Ŀ����ش���������һ��͹����ɽ��Ĵ�ʯ����׾����޲�
��޺�������ء���ʯƽ���ɲ������¶��ˣ�ʯͷ���²����������
�֣�����ʯ����

LONG);

  set("exits", ([ 
    "left" : __DIR__"shan11",
    "right" : __DIR__"shan12",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N����������ȥ��\n",who);
  message_vision ("$N��һ�����˴�ʯ����һ������������\n",who);
  who->unconcious();
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N��������������ȥ��\n",who);
  message_vision ("$N�������ˤ��̨�¡�\n",who);
  who->unconcious();
  return 1;
}
