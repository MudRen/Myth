// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gong1a.c

inherit ROOM;

void create ()
{
  set ("short", "��ǽ");
  set ("long", @LONG

��ǽ��ΰ���ô�ʯ��������ɣ�����Ʈ�Żʼ���졣ÿ��һ�ɾ�
����һ����¥���������ڱ���ìѲ�ߡ�ǽ����һ��ʯ·����ǽ��
��Զ����

LONG);

  set("exits", ([
        "east"         : __DIR__"gong1b",
        "south"        : __DIR__"gong2a",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

