// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

��������ʯ�����̳ɵ�С���ϣ����˾���������������ͷ�д�
������Ʈ��������ζ����Զ�������Ҽһ������׵���������
�д��˼�ե���͵Ĵ���ζ���ϱ���һ�͵꣬�������ơ�

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie4",
        "east"   : __DIR__"xiaojie6",
        "south"   : __DIR__"kedian",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



