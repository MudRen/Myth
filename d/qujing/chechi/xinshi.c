// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xinshi.c

inherit ROOM;

void create ()
{
  set ("short", "���п�");
  set ("long", @LONG

���п���ͨ�������˼ҵ�סլ�����ֿڿ���·����ʯש�̾ͣ�
������ԱȽϰ����ɾ���·����������һ�㣬��ʱ���Լ���һ��
��������ʻ����

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi5",
        "north"        : __DIR__"jieshi3",
        "south"        : __DIR__"jitan",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

