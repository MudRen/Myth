//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ����");
  set ("long", @LONG

ɽ�������ٸ߹ң���ݴ�������ʯ�ҷ�϶�м��ѿ�һ���󶴣�
�����������ƣ�������һ��ʯ���ң����У�������ɽĦ�ƶ���
�������֡�

LONG);

  set("exits", ([
        "north"   : __DIR__"jilei2",
        "northeast"   : __DIR__"jilei3",
        "southeast"   : __DIR__"shilang",
      ]));
  set("outdoors", __DIR__);

  setup();
}



