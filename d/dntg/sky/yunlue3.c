//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��·");
set("long", @LONG
    
̤�����������칬��·������Ʈ�������ƣ������˼�ũ��
��Ʈ����������̣����˱����Ŀ�������
LONG );


set("exits", ([
  "west"   : __DIR__"yunlue2",
  "east"   : __DIR__"yunlue4",
  "north"   : "/d/dntg/yaochi/wmj4",
  "northeast" :"/d/dntg/laojun/laojunmaze0.c",
  "south"   : "/d/dntg/yaochi/wmj3",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}

int valid_leave(object who, string dir) {

  if(dir=="northeast")  who->set_temp("laojunmaze/steps",5+random(5));
return ::valid_leave(who,dir);
}
