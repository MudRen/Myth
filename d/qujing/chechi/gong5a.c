// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gong5a.c

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
        "north"        : __DIR__"gong4a",
        "east"         : __DIR__"gong5b",
      ]));
  set("objects", ([
        __DIR__"npc/weishi"        : 1,
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

