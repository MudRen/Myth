// created by angell 1/1/2001
// room: /d/qujing/huangfeng/tulu1.c

inherit ROOM;

void create ()
{
  set ("short", "�����·");
  set ("long", @LONG

һ����·ͨ�����ߵ�С�壬���ӽ���Ⱥɽ֮�䣬һ��Ϫ���ƴ�
������ԶԶ���������м���Ȯ�ͣ����������Ͷ�ʱ����ɽ�裬
·�������������������߹�������Щ��ʵ�Ĵ���֮�ˡ�

LONG);

  set("exits", ([
        "eastdown"      : __DIR__"shanlu3",
        "west"      : __DIR__"tulu2",
       "south"   : __DIR__"inn",
       ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "eastdown")
    return 0;
  return ::valid_leave (who, dir);
}
