// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������������������һ�����߲�����������֮�����
���ˡ��������������ͷװٻ���������筺�ɫ��������һ���
��ǽ�������������컨���ϵ��ŵĻ�����š�

LONG);

  set("exits", ([
        "south"   : __DIR__"wumen",
        "east"   : __DIR__"gongyuan",
        "north"   : __DIR__"jinluan",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


