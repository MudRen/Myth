// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/tan.c

inherit ROOM;

void create ()
{
  set ("short", "̳��");
  set ("long", @LONG

������̳һ���ſ����м���һ��ͭ�󶦡���ҡ���������������
������Ȼ�����Ҹ���һ��ɫ������ͨ�������Ǽ�ˮ������������
�곡��

LONG);

  set("exits", ([
        "south"        : __DIR__"zhaomen",
        "north"        : __DIR__"wufeng",
        "east"         : __DIR__"qiyu",
        "west"         : __DIR__"jishui",
      ]));

  set("objects",([
       __DIR__"npc/jz2" : 1,
       __DIR__"obj/guizi" : 1,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

