// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiyu.c

inherit ROOM;

void create ()
{
  set ("short", "���곡");
  set ("long", @LONG

������һ��أ�ˮ��΢������������ڳ������ޡ������Ǻ�����
����������ĳ�������Χ��ǽ��������ƺ���������һ��ɫ����
ͨ��̳����

LONG);

  set("exits", ([
        "north"        : __DIR__"leiyu",
        "west"         : __DIR__"tan",
      ]));

  set("objects",([
         __DIR__"npc/jz3" : 1,
         __DIR__"obj/youguo" : 1,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

