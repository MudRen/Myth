// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang5g.c

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
        "north"        : __DIR__"dongmen",
        "south"        : __DIR__"qiang6g",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

