// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

һ�����ĵ��Ŷ��������Ϲ���һ��ʯ�ƣ��ϱ߿��ţ������̺�
��������֡�������������һ���ͨ��һ��������������һͨ
��ͨ�������

LONG);

  set("exits", ([
        "east"   : __DIR__"can",
        "northwest"   : __DIR__"da",
        "southwest"   : __DIR__"shanlu10",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



