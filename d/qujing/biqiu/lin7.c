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
        "northeast"    : __DIR__"lin6",
        "south"    : __DIR__"liu1",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

