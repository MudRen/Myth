// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��������칬�����ţ�ֻ��������������ǧ������һʱ���
����Щ��֪���룬���˶��񣬲ŷ�������������ͣ�����ױ�ɡ�
���ɷǷ���������һ���ţ������칬�ˡ���������ȥ��ֻ����
�����ƣ�һ������������ԼԼ�ؿ��������������������ֳֳ�
ǹ�������ż�������콫������Ѳ�ߡ�

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/zz-tianwang" : 1,
//  __DIR__"npc/tian-ding2" : 1,
//  __DIR__"npc/tian-ding1" : 1,
  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sw1",
  "north" : __DIR__"nanmenting",
  "east" : __DIR__"se1",
]));
create_door("north", "������", "south", DOOR_CLOSED);

  setup();
}
 
int valid_leave(object me, string dir)
{
 
        if (dir != "north") {
                return ::valid_leave(me,dir);
        }
 
 
        if (objectp(present("zengzhang tianwang", environment(me)))) {
 
                if (me->query("combat_exp")<100000) {
return notify_fail(HIY"������������˵����" + RANK_D->query_respect(me) +"�ƺ���δ���ɵ�����ȥ���µ�๦�ɡ�\n������ʧ�����뿪�ˡ�\n"NOR);

                }
                else {
return notify_fail(HIY"�����������㹰�����˸�Ҿ����λ" + RANK_D->query_respect(me) +"��ʵ�ڶԲ�����ͥ����׼����Ҵ�ᣬ�ݲ��Ӵ���͡�\n�������´��ˡ�\n"NOR);
                }
        }
return ::valid_leave(me,dir);
}
