// created by snowcat.c 4/4/1997
// room: /d/nuerguo/fronthall.c

inherit ROOM;

void create ()
{
  set ("short", "ǰ��");
  set ("long", @LONG

����������ǰ��������һ�������Ϻ��ʣ����ܵ��������
�Ի͡�����������һ�ų�����������ˮ������ñ������ã�
�����Ҳ���һ��������Ů�����Ź�ͥ�赸��

LONG);

  set("exits", ([
        "north" : __DIR__"backhall",
        "east"  : __DIR__"easthall",
        "west"  : __DIR__"westhall",
        "south" : __DIR__"entry",
      ]));

  set("objects", ([
         __DIR__"npc/girl" : 2,
     ]));

  setup();
}






