// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "Ǭ����");
  set ("long", @LONG

����������һ��ˣ�����������Ʈ���������濴ȥ�е�����
¥����������������֮���ڡ����������ֵĽֵ�����ʱ����һ
Щ���ӵ�������

LONG);

  set("exits", ([
        "east"    : __DIR__"gongmen",
        "north"    : __DIR__"jitan",
        "west"    : __DIR__"jiedao2",
        "south"    : __DIR__"beishi",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

