#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��̨С��");
  set ("long", @LONG

һ����ʯ�̳ɵ�С·ͨ��̶�����С���ϵ���ʯ�ڳ��˲�ͬͼ
������԰�£����¡�����һ·��ȥ�����Ǹ��ָ�����������С��
����ɨ�ĺܸɾ�����ͨ�������������ס����
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
//  set("outdoors", 1);
  

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"shuangyu",
  "west" : __DIR__"yuetai1",
]));
//      
        set("water", 1);
//  
  setup();
}

