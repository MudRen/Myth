// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/fang.c

inherit ROOM;

void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

����¥����Ӹɾ���ֻ��һ��ľ���������м����𾭣�����ľ��
��ľ�㴸��������һ�ų�����ľ�������м����޲��������ϱ���
ľ�ݣ�����ͨ���

LONG);

  set("exits", ([
        "southdown"     : __DIR__"hou",
      ]));

  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

