// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

������һƬ���ס�������ɰ�ľ¥Ҳ��ʯש���ߵ�ƽ�����Ҽ�
�����ŵƽ�����ʮɫ���в��ٴ�С��������ɫ�Ĳʵƹ��ڴ�
����ǰ���ſ���һ���͹ޣ������Ϳ͹���֮�á�

LONG);

  set("exits", ([
        "south"   : __DIR__"xiaojie6",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
        __DIR__"obj/pot"   : 1,
      ]));
  set("has_oil",1);
  set("has_oil_pot",1);
  set("outdoors", __DIR__);

  setup();
}

void regenerate_oil ()
{
  call_out ("regenerating_oil",600);
}

void regenerating_oil ()
{
  this_object()->set("has_oil",1);
}



