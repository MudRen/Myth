// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ����С�ֵ�����ԶԶ�ɼ�һ���ţ�����ԶԶ
�ɼ�һ��¥��

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie3",
        "south"   : __DIR__"xiaojie7",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



