//Cracked by Roath
// Room: /d/nanhai/fanting
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ͨ��ի�������ȣ�����ɽ���˵�������իǰ�����ڴ�
С�Ƭ�̣����˳˻�Ѱ��һЩҩƷ�鵤������������
LONG);
/*
������
�ƺ���һ��С��ͨ�����ݡ�
*/
//  set("item_desc", ([ /* sizeof() == 1 */
//  "south" : (: look_door,     "south" :),
//]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaoyuan",
  "south" : __DIR__"restroom",
  "east" : __DIR__"zhaifang",
//  "north": __DIR__"restroom",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangchu" : 1,
]));
//create_door("south", "С��", "north", DOOR_CLOSED);

  setup();
}
int valid_leave(object me, string dir)
{
if (me->query("family/family_name") != "�Ϻ�����ɽ" && dir == "east")
if(objectp(present("zhangchu seng", environment(me))))
return notify_fail("�Ƴ�ɮ������ס�㣺�����Ǳ��ɳ�����" + RANK_D->query_respect(me) + "��������\n");   
return ::valid_leave(me, dir);
}
