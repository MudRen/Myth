// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "լԺ");
  set ("long", @LONG

����լԺ��ס�ż����˼ң��Ҽ��ſ���ľդ��ľ���ӣ�Ժ��
���м��ó���������������˽��ɫ�ĳ��ӡ�����ǣ�ż�����
�ӣ�����ϴ�����·���

LONG);

  set("exits", ([
        "south"    : __DIR__"zhai2",
        "west"    : __DIR__"jie4",
      ]));
  set("objects", ([
        __DIR__"obj/elong"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

