// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang7g.c

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
        "north"        : __DIR__"qiang6g",
        "west"         : __DIR__"qiang7f",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

