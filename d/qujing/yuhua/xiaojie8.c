// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ�����ֵ�������һ��ľ¥���ſڹ���һ��
�ƣ���������

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie7",
        "south"   : __DIR__"dianshan",
        "east"   : __DIR__"xiaojie9",
      ]));
  set("outdoors", __DIR__);

  setup();
}



