// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ����С�ֵĶ�������ͣ����������һ�ҹ�
���Ĵ��͹ݡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie8",
        "east"   : __DIR__"daike",
      ]));
  set("outdoors", __DIR__);

  setup();
}



