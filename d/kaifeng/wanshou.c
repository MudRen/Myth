//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���ٹ���");
  set ("long", @LONG

���ٹ������ϴ󿪣��������ľ��ɣ���������ͭ���������������
��һ����������չ�����ɡ��ű��Ϸ���һ�����ĵ����䣬��������
���ػ���

LONG);

  set("exits", ([
        "southdown" : __DIR__"guting1",
        "north" : __DIR__"sanxin",
      ]));
  set("objects", ([
        __DIR__"npc/gongwei" :  2,
        __DIR__"obj/diaoyu" :  1,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "north")
    return ::valid_leave (who, dir);

  if (! who->query_temp("kaifeng_donate_silver"))
    return notify_fail ("���(donate)һ�����ӵ����������ӭ��裺��\n");

  return ::valid_leave (who, dir);
}

