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
        "southdown"   : __DIR__"shanlu7",
        "northeast"   : __DIR__"shanlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



