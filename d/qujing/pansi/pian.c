// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

ƫ����ǽ��������һ�����������裬�����Ϲ��е�ҩ��«����
̨�Ϸ��м�����ޡ����������ķ���б���Σ������Ŵ󿪣�ͨ
����ĵ��á�

LONG);

  set("exits", ([
        "east"    : __DIR__"zheng",
      ]));
  set("objects", ([
        __DIR__"npc/dao"    : 1,
      ]));
  setup();
}

