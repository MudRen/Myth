// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

�����ǽֵı���ͷ��������ʯ�����̳ɵ�С���ϣ����˾�����
����������ͷ�д�������Ʈ��������ζ����Զ�������Ҽһ�
�����׵����������д��˼�ե���͵Ĵ���ζ��

LONG);

  set("exits", ([
        "north"   : __DIR__"minju1",
        "east"   : __DIR__"minju2",
        "south"   : __DIR__"xiaojie3",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



