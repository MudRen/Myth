// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯͷ��");
  set ("long", @LONG

ʯ������̦���ƣ���һ�Ŷ���Ȼ���ɡ��ſڹ�ʯ�����������ޣ�
��������е�ˮ���£���������������һľͤ�����Ͽɼ�һ
��ңʯԺ��

LONG);

  set("exits", ([
        "north"   : __DIR__"muxiang",
        "south"   : __DIR__"shiyuan",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

