// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zheng.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������������������м�ı����ϸ߹����������������ޣ���
�С���¯�����������������Ǿ���Щ����Ҳ��ɨһ������������
������ͨ���յ

LONG);

  set("exits", ([
        "west"          : __DIR__"jingang",
        "east"          : __DIR__"hou",
      ]));

  set("objects", ([
         __DIR__"npc/heshang"    : 2,
      ]));
  setup();
}

