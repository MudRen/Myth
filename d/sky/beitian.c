//beitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "������");
  set ("long", @LONG

    �������칬�ı��š���ʴ�۵ı������������ϵģ����Գ�����
����ʥּ����۵�����֮�⣬û�˸Ҵ�������롣����������������
�߿ɾ�������ˡ���Ȼ��ˣ���������Ŀ�˿�����������ʺ�Ĵ���
���������������ͭ�����Ե�����Ƿ��������������Ŵ����춡����
�����һ˿������Ѳ���š�

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("objects", ([ /* sizeof() == 4 */
//  __DIR__"npc/tian-ding2" : 1,
//  __DIR__"npc/tian-ding1" : 1,
  __DIR__"npc/hg-tianwang" : 1,
  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nw1",
  "south" : __DIR__"beimenting",
  "north" : __DIR__"yun",
  "east" : __DIR__"ne1",
]));
create_door("south", "������", "north", DOOR_CLOSED);

  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir == "north") {
        	message_vision ("$N���������ƺ��У�\n",me);
        	return ::valid_leave(me,dir);
        }
        if (dir != "south") {
                return ::valid_leave(me,dir);
        }
 
 
if (objectp(present("huguo tianwang", environment(me)))) {
 
if (me->query("combat_exp")>100000) 
return notify_fail(HIY"�����������㹰�����˸�Ҿ����λ" + RANK_D->query_respect(me) +"��ʵ�ڶԲ��������ȥ���Ǵ������߰ɡ�\n�������ﲻ�ܽ���\n"NOR);
else
return notify_fail(HIY"������������˵���������칬�صأ������˵Ȳ������ڣ�\n������ʧ�����뿪�ˡ�\n"NOR);
        }
return ::valid_leave(me,dir);
}

