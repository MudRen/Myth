// created by angell 1/1/2001
// room: /d/qujing/huangfeng/dong3.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ������û����ע���㣬���ǿ�Щ�뿪�ɡ�

LONG);

  set("exits", ([
        "south" : __DIR__"dong1",
        "east" : __DIR__"ting",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));

  setup();
}
