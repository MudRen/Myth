// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "���¥");
  set ("long", @LONG

���¥�ϲʴ����裬¥����Ⱥ�����������ճ�������ģ�����
����ʱ�����ð�ҹ�������������ǽֵ����ϱ����������һ
Щ���ӡ�

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao5",
        "east"    : __DIR__"jiedao6",
        "north"    : __DIR__"zahuopu",
        "south"    : __DIR__"mipu",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

