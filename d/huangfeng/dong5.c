// created by angell 1/1/2001
// room: /d/qujing/huangfeng/dong5.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ������û����ע���㣬���ǿ�Щ�뿪�ɡ�

LONG);

  set("exits", ([
	"north" : __DIR__"chang",
        "south" : __DIR__"dong6",
        "east" : __DIR__"dong4",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));
      
  setup();
}