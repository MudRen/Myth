// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

���������Ǹ����ûʵĸ��ţ����뱱����ʯ�����̳ɵ�С�֣�
���˾���������������ͷ�д�������Ʈ��������ζ����Զ
�������Ҽһ������׵����������д��˼�ե���͵Ĵ���ζ��

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie2",
        "west"   : __DIR__"fumen",
        "east"   : __DIR__"xiaojie5",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



