// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

һ������ʯ��ʵ��С�֡�С�����������������һЩ���ˣ�
���ϲ�ʱ����ʻ����С�ֵ�������һ��¥�������һ����
�ӣ���ʷ�ݡ�

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie6",
        "west"   : __DIR__"changshi",
      ]));
  set("outdoors", __DIR__);

  setup();
}



