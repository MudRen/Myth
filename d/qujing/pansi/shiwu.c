// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

�仨������һ����ʯ�ݣ��ݱ��������֦֦�㣬�ݺ��÷ҶҶ
�档ʯ�����ϻ����ʢ��������ȸݺ��������ʯ��һ���ǻ���
��������һ���Ǳ�Ϫ������

LONG);

  set("exits", ([
        "west"    : __DIR__"huajian1",
        "northeast"    : __DIR__"bixi1",
        "southeast"    : __DIR__"bixi4",
        "enter"    : __DIR__"wunei",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

