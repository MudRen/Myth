// created by angell 1/1/2001
// room: /d/qujing/huangfeng/shanlu2.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ�����ܣ���·�������У����������ֻ���������ȳ���
�ǡ����а�����������ɱ������ʱ�����������������ǿ�Щ
�뿪�ɡ�

LONG);

    set("exits", ([
        "eastdown"      : __DIR__"shanlu1",
        "northwest"      : __DIR__"shanlu3",
        "south"   : __DIR__"linzhong",
      ]));
  set("objects", ([
                __DIR__"npc/laohu": 2 ]) );

  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object me, string dir)
{
  	if (dir == "south"){
    		message_vision ("$N�����������У����������ϱ���֦�����˼�����\n",me);
  	}
	if (dir == "northwest" ) {
  	if (objectp(present("lao hu", environment(me))))
        return notify_fail("�ϻ�ֻ����һԾ���ͽ��㵲�˻�����\n");
        }
  return 1;
}

