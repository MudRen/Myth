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
        "west"   : __DIR__"jiedao11",
        "east"   : __DIR__"jiedao13",
        "south"   : __DIR__"jiuguan",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



