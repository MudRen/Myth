// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

һ���޴��ʯ����������ǰ��ʯ�����С���ɽ���������֡�
�����������ƣ���һ�ɹ������Ӷ���������ʯ���Ķ�������һ
�����ش����ϱ�ͨ���ﶴ��

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shanshi2",
        "south"   : __DIR__"dongnei1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));

  setup();
}



