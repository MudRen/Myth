// rewritten by snowcat on 4/11/1997
// room: cuiyun2

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

  set("objects", ([
        __DIR__"npc/qiaofu" : 1,
      ]));
  set("outdoors", "firemount");
  set("exits", ([
        "eastdown" : __DIR__"cuiyun3",
        "southup"  : __DIR__"cuiyun1",
      ]));
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
