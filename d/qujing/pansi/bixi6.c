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
        "north"    : __DIR__"bixi3",
        "west"    : __DIR__"bixi5",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

