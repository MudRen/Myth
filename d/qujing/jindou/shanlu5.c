// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ·������Ⱥɽ����֮������������У�����������̦޺��ɽ
�ң���ʯ���ﳤ�����ɴ�ء�·�Ͼ�����ʯҰ�ݣ���ʱ��һЩ
��֦������š�

LONG);

  set("exits", ([
        "east"   : "/d/qujing/tongtian/xiaolu1",
        "west"   : __DIR__"shanlu4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



