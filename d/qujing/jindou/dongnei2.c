// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���Ķ����������ڣ������ϳ��Ŵֳ������٣���ͷ�Ϲ�������
���ڲ������ͻ�ѣ�֨֨��ð���̣����������������ĵ�����
��ƽƽ����������һ��һ��ʯ�塣

LONG);

  set("exits", ([
        "east"   : __DIR__"dongnei3",
        "south"   : __DIR__"dongnei4",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));

  setup();
}



