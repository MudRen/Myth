// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

ɽ·����������խ�������Ǹ߸ߵ�ɽ�ң�����ȥ��һ��Ȼ��
���ϡ�·��һ�߳���һƬƬ�Ĺ�ľ�ԣ���һ�߳������ظߵ�Ұ
������ҡ�ꡣ

LONG);

  set("exits", ([
        "north"   : __DIR__"shan1",
        "southeast"   : __DIR__"shan2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



