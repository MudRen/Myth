// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ�������洫��һ��һ��ĸ���������Ʈ����
�˵���ζ��

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie2",
        "south"   : __DIR__"xiaojie4",
        "east"   : __DIR__"geguan",
        "west"   : __DIR__"jiulou",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



