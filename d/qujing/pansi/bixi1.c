// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ϫ");
  set ("long", @LONG

ֻ��������Ϫ�������������졣Ϫˮ��������������������ʯ
�ݡ�Ҳ����Ұ����������Ҳ������¹�����졣�����Ǹ��ɼ�ȥ
�������������Ѱ�õ���

LONG);

  set("exits", ([
        "southwest"    : __DIR__"shiwu",
        "east"    : __DIR__"bixi2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

