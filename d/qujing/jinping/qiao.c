// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�����ŵƽ�ʣ����ֲʵ�ֽ���߸��������Ϸ����Ŵ�С��յ
����ף�ɢ���������͵Ĵ���ζ�����������������շ�ͬѰ��
��������һ�㡣

LONG);

  set("exits", ([
        "north"   : __DIR__"qiaobei",
        "south"   : __DIR__"qiaonan",
      ]));
  set("objects", ([
        __DIR__"obj/gang"   : 3,
        __DIR__"npc/dengguan"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



