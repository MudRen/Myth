// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

���н���������Ҷ�ĵ�·�ϣ��������������ϡϡ���ɵ���֦
��ɢ���������⾰������ɽ��ˮ����������ֻ���Ƿ׷�Ұ��ӯ
����������������䡣

LONG);

  set("exits", ([
        "west"    : __DIR__"lin3",
        "east"    : __DIR__"ximen",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

