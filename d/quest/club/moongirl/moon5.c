//�������¹�
//by junhyun@SK
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "�������¹�");
  set ("long", @LONG

һ����������ʧ���ŵĹ�������񾫵�ϸ�����ɵĹ�����
��б��һ�ˣ������ǡ�������¡����뱦����


LONG);
        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"huayuan", 
       "south" : __DIR__"gong5",
       "west" : __DIR__"sleep",
       "down" : __DIR__"in", 
         "east" : __DIR__"chitang", 
// delete......no use mudring..........

        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/junhyun" : 1,
        ]));

create_door("west", "��������", "east", DOOR_CLOSED);
        set("no_clean_up", 0);
        set("no_fight", 1); 
        set("no_magic", 1); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

