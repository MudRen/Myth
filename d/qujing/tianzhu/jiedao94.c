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
        "west"   : __DIR__"jiedao93",
        "northeast"   : __DIR__"jiedao85",
        "southeast"   : __DIR__"nanmen",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



