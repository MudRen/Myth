//xitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;

int valid_leave();

void create ()
{
  set ("short", "������");
  set ("long", @LONG

    ���ſ����칬��ƽ�ֵ����۴���Ⱥ���ĵط���ǽ�ﴫ������
���֣��������Ů��������ɡ���������������֣����ɵ������ˡ�
��������һ�գ��˼�һ�ꡣ�㵽���ڲ�֪��Ϊʲô���칬��ʱ�����
��ô�졣

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/tian-ding2" : 1,
  __DIR__"npc/tian-ding1" : 1,
//  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wn1",
  "south" : __DIR__"ws1",
  "east" : __DIR__"ximenting",
]));
create_door("east", "������", "west", DOOR_CLOSED);
  set("no_clean_up", 2);

  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir != "east") {
                return ::valid_leave(me,dir);
        }
 
if (::valid_leave(me,dir)) return notify_fail("������ܴ����ų��룬��ݻ��Ǵ����Ž��ɣ�\n");
}
