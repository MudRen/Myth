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
        "northeast"   : __DIR__"dongnei1",
        "west"   : __DIR__"dongnei2",
        "southwest"   : __DIR__"dongnei4",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 4,
        __DIR__"npc/dujiao"   : 1,
      ]));

  setup();
}



