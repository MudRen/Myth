// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ����С�ֵ����洫���������������ſڹ�һ
�����ơ�

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie1",
        "south"   : __DIR__"xiaojie3",
        "west"   : __DIR__"tiejiang",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



