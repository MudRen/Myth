// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ����С�ֵĶ�������Ӫ������������¥ͨ��
���⡣

LONG);

  set("exits", ([
        "north"   : __DIR__"menlou",
        "south"   : __DIR__"xiaojie2",
        "east"   : __DIR__"shaoying",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



