//sgzl

#include <room.h>
inherit ROOM;

string *ways = ({
  "/d/dntg/donghai/mazea",
  "/d/dntg/donghai/mazeb",
  "/d/dntg/donghai/maze3",
  "/d/dntg/donghai/maze2",
  "/d/dntg/donghai/maze1",
});

void create()
{
set("short", "�����Թ�");
set("long", @LONG
��ˮ�ֱ���峺�ˣ������Ѿ������ҵ������ˡ�    
���ܵľ������һ����Ҫ��û����·�Ļ�����
���ѳ�ȥ�ˡ�
LONG );


set("exits", ([
  "south"   : __DIR__"maze5",
  "west"   : ways[random(sizeof(ways))],
  "north"   : ways[random(sizeof(ways))],
  "east"   : ways[random(sizeof(ways))],
]));


set("objects", ([
     __DIR__"npc/xiaoyu"  : 1,
]));




setup();
}


void init()
{
      if(this_player()->query("id")=="xiao hong yu"
      || this_player()->query("id")=="xiao qing yu"
      || this_player()->query("id")=="xiao lan yu"
      || this_player()->query("id")=="xiao bai yu"
      || this_player()->query("id")=="xiao hua yu"
      || this_player()->query("id")=="xiao jin yu"
        )
        message_vision("$N���˹�����\n",this_player());
}

int valid_leave(object me, string dir)
{
      if(this_player()->query("id")=="xiao hong yu"
      || this_player()->query("id")=="xiao qing yu"
      || this_player()->query("id")=="xiao lan yu"
      || this_player()->query("id")=="xiao bai yu"
      || this_player()->query("id")=="xiao hua yu"
      || this_player()->query("id")=="xiao jin yu"
        )
       message_vision("$N����β�������ˡ�\n", this_player());
       return ::valid_leave(me, dir);
}

