//sgzl

#include <room.h>
inherit ROOM;

string *ways = ({
  "/d/dntg/donghai/maze1",
  "/d/dntg/donghai/mazeb",
  "/d/dntg/donghai/maze2",
  "/d/dntg/donghai/mazed",
  "/d/dntg/donghai/mazee",
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
  "east"   : ways[random(sizeof(ways))],
  "west"   : __DIR__"maze1",
  "north"   : ways[random(sizeof(ways))],
  "south"   : ways[random(sizeof(ways))],
]));


set("objects", ([
     __DIR__"npc/jinyu"  : 1,
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

