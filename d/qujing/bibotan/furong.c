#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ܽ��ͤ");
  set ("long", @LONG

ܽ��ͤ���а˽ǣ��ϵ�����ʷ�����а����ָ��˸���λ��
ͤ��һ��԰����ʯ�����Ͽ��м����һ��̫��ͼ������Χ�˸�ʯ
�ʣ������Է�λ���á��κεķ紵�ݶ��ƺ���������һЩ������
�磬�춯��ҡ��ǰ�ס�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/table" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hua_qian",
  "east" : __DIR__"hua_li",
  "north" : __DIR__"hua_kun",
  "west" : __DIR__"hua_kan",
]));
//      
        set("water", 1);
//  
  setup();
}

