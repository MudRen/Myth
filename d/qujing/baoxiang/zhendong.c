// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zhendong.c

inherit ROOM;

void create ()
{
  set ("short", "�򶫳�");
  set ("long", @LONG

�򶫳���ʯǽȦ�𣬳�����һ�ڴ�ʯ�������Ķ���פ������������
���Ϸ�����Ǹ�ǽ�������湬���������������أ�������Ǳ�
���������

LONG);

  set("exits", ([
        "west"       : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/bing" : 4,
      ]));

  set("resource", ([ 
    "water" : 1,
    ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

