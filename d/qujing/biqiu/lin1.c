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
        "southeast"    : __DIR__"lin2",
        "west"    : __DIR__"dongmen",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

