// created by angell 1/1/2001
// room: /d/qujing/huangfeng/dong1.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ������ͨ�򶴵�����ϱ��ǳ����Ķ��ڡ�

LONG);

  set("exits", ([
        "south" : __DIR__"dongkou",
        "west" : __DIR__"dong2",
	"north" : __DIR__"dong3",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));
 
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
    return 0;
  return ::valid_leave(who,dir);
}
