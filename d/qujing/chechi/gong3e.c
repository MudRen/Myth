// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gong3e.c

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
        "south"        : __DIR__"gong4e",
        "north"        : __DIR__"gong2e",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

