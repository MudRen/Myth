// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ�ֿ����ش���һ��ճ��أ���������һƬ��Ժ���·�������
֮�С���Ժǰ����һ�ߴ��ɽ�ţ����Կ����������Ժ������
��һ�����ң��������¡�

LONG);

  set("exits", ([
        "south"   : __DIR__"siyuan",
        "northeast"   : __DIR__"baijiao",
      ]));
  set("objects", ([
        __DIR__"npc/monk"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "northeast")
    return 0;
  return ::valid_leave (who, dir);
}
