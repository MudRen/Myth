// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "ҩ��");
  set ("long", @LONG

ҩ��������ҩ�񣬹����Ǵ��СС��ͭ�ѳ��룬������������
������ҩǩ��һ�Ŷ���ľ���������м䣬���ż�ֻ��ҩ�Ѻͺ�
��ҩ���ӡ�

LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao5",
      ]));
  set("objects", ([
"/obj/boss/qinfa_zheng"    : 1,
      ]));
  setup();
}

