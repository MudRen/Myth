// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ĳ�ǽ��ʯ�����ͣ�������Ļ��Ǻ��Ѽ����ɺԣ�������
һ����¥���������Ȼ�ͭ��Ӳľ���ţ�����һ˫��ʯ������
ͨ������⡣

LONG);

  set("exits", ([
        "east"    : __DIR__"dalu1",
        "west"    : __DIR__"zhongshi",
      ]));
  set("objects", ([
        __DIR__"npc/junshi"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "east")
    return 0;
  return ::valid_leave(who,dir);
}

