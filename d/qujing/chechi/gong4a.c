// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gong4a.c

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
        "south"        : __DIR__"gong5a",
        "north"        : __DIR__"gong3a",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

