// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gong1d.c

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
        "east"         : __DIR__"gong1e",
        "west"         : __DIR__"gong1c",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

