// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ������������������Ǹ�ʽ�������̵�����ƹ�ҩ���ȵȣ�
Ӧ�о��С��廨���ŵ���������ٽ����𣬲�ʱ������������
��ߺ�����ӽ��ϴ�����

LONG);

  set("exits", ([
        "west"   : __DIR__"guanglu",
        "north"   : __DIR__"jiedao28",
        "south"   : __DIR__"jiedao48",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



