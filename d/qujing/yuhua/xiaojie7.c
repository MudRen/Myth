// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ�����ֵ�������һȺ¥���������������
�ڵء�

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie4",
        "south"   : __DIR__"fumen",
        "east"   : __DIR__"xiaojie8",
        "west"   : __DIR__"xiaojie6",
      ]));
  set("outdoors", __DIR__);

  setup();
}



