// ����С· by Calvin

inherit ROOM;

void create()
{
  set ("short", "����С·");
  set ("long", @LONG

�����ɽ��Ǵ�˵�е��ɽ�,��������᫵�ɽ·��ôҲ
���˲��������ǵĵط����ж�ô��������

LONG);

  set("exits", ([ 
    "west" : __DIR__"lu6",
    "east" : __DIR__"lu8",
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

  message_vision ("$N����һ���ʯ����������ȥ��\n",who);
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

