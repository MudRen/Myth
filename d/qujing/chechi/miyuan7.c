// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/miyuan.c

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

������һ�����ܵ��ķ�ͥԺ�������Ǹ�ǽ��Ժ������ϰϰ���
��ʢ�����ϱ��ǲؾ�¥�ĺ�ǽ��ǽ����һ��ͨ����

LONG);

  set("exits", ([
        "south"    : __DIR__"cangjing",
      ]));

  set("objects", ([
         __DIR__"npc/langli"    : 1,
         __DIR__"npc/chaili"    : 1,
         __DIR__"npc/beili"    : 1,
         __DIR__"npc/mali"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

