// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

������ʯ�����̳ɵ�С���ϣ����˾���������������ͷ�д���
����Ʈ��������ζ����Զ�������Ҽһ������׵�����������
���˼�ե���͵Ĵ���ζ��

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie1",
        "east"   : __DIR__"minju4",
        "south"   : __DIR__"xiaojie7",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



