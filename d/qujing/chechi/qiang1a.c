// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang1a.c

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
        "south"        : __DIR__"qiang2a",
        "east"         : __DIR__"qiang1b",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

