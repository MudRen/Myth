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
        "east"    : __DIR__"shandao4",
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

  message_vision ("$N�����۾�һ����ವ�һ��Ծ�˹�ȥ��\n",who);
  who->move(__DIR__"jiankou1");
  return 1;
}
