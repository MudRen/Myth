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
        "north"    : __DIR__"lin5",
        "southwest"    : __DIR__"lin7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

