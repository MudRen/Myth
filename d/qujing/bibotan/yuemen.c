#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ǡ��һ�����£���ǰ���ͺ�Ժ������һ���С��δ��������
������Ժ�ģ��ڴ˲�������������Ӱ�����ŷ��д�����������
����������Щ����׵��������ƽ��˿���ܡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/qingshan" : 1,
  __DIR__"npc/niqiu" : 1,
]));
//  set("outdoors", 1);
  

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"longtai2",
  "north" : __DIR__"hua_qian",
  "east" : __DIR__"yuetai1",
]));

  create_door("north", "������", "south", DOOR_CLOSED);
//      
        set("water", 1);
//  
  setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("tianboer xiao", environment(me))))
        return notify_fail("�첨��Ц�ȵ�����Ժ�ǽ��أ�����Īȥ�ĺã�\n");
        if (objectp(present("xiaoboer tian", environment(me))))
        return notify_fail("Ц������ȵ�����Ժ�ǽ��أ�����Īȥ�ĺã�\n");
        }   
        return ::valid_leave(me, dir);
}

