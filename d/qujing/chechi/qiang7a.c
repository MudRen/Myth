// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang7a.c

inherit ROOM;

void create ()
{
  set ("short", "��ǽ");
  set ("long", @LONG

�ߴ�ĳ�ǽ�������ɶ�ߣ��ɻ��Ҽл������ɡ���ǽ�ϰ߲߰�����
�������Ѿ���Щ����ˣ����ų�����ǽ����һ����ʵ����ʯ·��
���������߳���

LONG);

  set("exits", ([
        "north"        : __DIR__"qiang6a",
        "east"         : __DIR__"qiang7b",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

