// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jishui.c

inherit ROOM;

void create ()
{
  set ("short", "��ˮ��");
  set ("long", @LONG

���Ϲ���һ�����ߵ�ʯ����Ȫˮ�Ծ����������������ߴ�����
��������ʱ����Ҳ�Ǽ�ˮ�ĳ��������������ޱȡ����ߵ���ɫ��
��ֱ̳ͨ����

LONG);

  set("exits", ([
        "north"        : __DIR__"fengyun",
        "east"         : __DIR__"tan",
      ]));
  set("objects", ([
        __DIR__"npc/jz1" : 1,
        __DIR__"obj/chantai" : 2,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

