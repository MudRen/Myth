// room.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

����������կ�Ĵ��ã�����������������һʮ���Ż�Ƥ���η�
�����ԣ�����һ����̨�����Źع���ۡ�ɽկ���ͷ��Ҫ�����
��������ѡ��������С�����Ҳ�Ƿ������ĵط���
LONG);


set("exits", ([ /* sizeof() == 4 */
"southdown" : "/d/gao/shanlu",
"east" : "/d/gao/neishi",
]));

 set("objects", ([ /* sizeof() == 2 */
"/d/gao/npc/head" : 1,

]));
create_door("east", "ʯ��", "west", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
}



int valid_leave(object me, string dir)
{
    if ( dir == "east" ) {
        if(objectp(present("xia pengzhan", environment(me))))
            return
notify_fail("����չһ������������ǰ�棬��Ц����\n���կ�������������������߱���ĵĵط���\n");
    }
    return ::valid_leave(me, dir);
}




