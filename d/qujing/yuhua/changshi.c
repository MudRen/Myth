// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʷ��");
  set ("long", @LONG

��ʷ���ſڷ�������ͭʨ������Ϊһ���ã����з���һ������
��һ��ϸ�ɲ�ߡ����ֱ���һ���������������౾���Ĺ�
���ı���

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie5",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));

  setup();
}



