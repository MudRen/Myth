// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ����С�ֵ�������һ��ש��¥�����飺����
�������������֡�

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie5",
        "south"   : __DIR__"shenli",
        "east"   : __DIR__"xiaojie7",
      ]));
  set("outdoors", __DIR__);

  setup();
}



