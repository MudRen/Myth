// Room: /city/erlou.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create()
{
set("short", "��¥�ͷ�");
set("long", @LONG

�ͷ�������󷽣����ܷ��Ŵ��̺͵�ľС�����ٽ���һ�Ŵ��ӣ���
�ű��������Ǹ�Ъ����Ϣ�ĺõط���

LONG);

  set("sleep_room",1);
  set("if_bed",1);

  set("exits", ([
    "down" : __DIR__"kezhan",
  ]));

  setup();
}

int valid_leave(object me, string dir)
{
  me->delete_temp("rent_paid");
  return ::valid_leave(me, dir);
}

