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
        "westup"   : __DIR__"jindou3",
        "northeast"   : __DIR__"shanlu4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



