//sgzl
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "ɽ��");
	set ("long", @LONG

�������ѩɽ����ƽ����ӵĴ����ˣ����ϻ���
����ѩ����������ѩɽ���ӴӲ��е��Ϻ���
LONG);


	set("exits", 
	([ //sizeof() == 4
                "down" : __DIR__"xuejie-2",
                "north" : __DIR__"shanpohou",
                "east" : __DIR__"chufang",
                "west" : __DIR__"restroom",
	]));
	
	set("objects", 
	([
                "/d/xueshan/obj/rack" : 1,
	]));


	set("outdoors", "xueshan");

        create_door("east", "������", "west", DOOR_CLOSED);
        set("no_clean_up", 0);

	setup();
}



