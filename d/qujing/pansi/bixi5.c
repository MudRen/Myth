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
        "east"    : __DIR__"bixi6",
        "west"    : __DIR__"bixi4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

