// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ΪһƬ�����ش���������¥��ƽ���ѱ���жһ�գ�������
ԭ��һ������֪�ιʱ��Ƶ���ֻʣ�²�שʣ�ߡ�������һ
����¥���ϱ����߸���һ�㳡�������г����Ľֵ���

LONG);

  set("exits", ([
        "north"    : __DIR__"beishi",
        "south"    : __DIR__"nanshi",
        "east"    : __DIR__"dongmen",
        "west"    : __DIR__"jiedao7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

