// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ſڷ���һ��ͭ�󶦣�����ɢ���������͵Ĵ���ζ������
��һ��ߺ���ľ�������������յ�����͵ƣ��������յ�һƬ
ͨ����

LONG);

  set("exits", ([
        "northwest"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi3"  : 1,
      ]));

  setup();
}



