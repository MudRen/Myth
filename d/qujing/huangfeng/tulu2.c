// created by angell 1/1/2001
// room: /d/qujing/huangfeng/tulu2.c

inherit ROOM;

void create ()
{
  set ("short", "�����·");
  set ("long", @LONG

���Ӻ�С��ֻ��������������լ�����ϵĵ���Ҳ���࣬·��
��һ��ҩ�꣬��������ģ�����ûʲô���⡣

LONG);

  set("exits", ([
        "east"      : __DIR__"tulu1",
        "west" : __DIR__"tulu3",
        "south"   : __DIR__"yaopu",
        "north"  : __DIR__"minju1",
      ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}
