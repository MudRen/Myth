// rewritten by snowcat on 4/11/1997
// Room: cuiyun4

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

ɽ����ľ�дУ����������һ�����ﻨ��ľ���ɽ��Ρ����ʣ�
ɽ���������ƣ�������������Դ������������������������������
��ľ֮����·����һ��һ�����߰������֦������ȥ���������˷�
������

LONG);

  set("exits", ([
        "southup"  : __DIR__"cuiyun3",
        "eastdown" : __DIR__"cuiyun5",
      ]));
  set("outdoors", "firemount");

  setup();
}


void init()
{
  add_action("do_search", "search");
}

int do_search (string arg)
{
  object me = this_player();

  if (!arg || arg != "bone")
  {
    message_vision ("$N����ȥѰ��ʲô��\n",me);
    return 1;
  }

  message_vision ("$N����ȥ�ڿ���֦����ҷ���������\n",me);
  return 1;
}
