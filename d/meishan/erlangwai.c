
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

�����Ƕ�����ǰһ���㳡������һ����������ֺ裬�Ǳ���
�������������ⳡ�����в���������Ů����ͭ¯��������
�ƣ��������ʢ��������һ��Ƭ���꣬�཭ˮ�����»�����
����
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/laotai" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : "/d/meishan/denglong3",
  "north" : "/d/meishan/erlangmiao",
  "east" : __DIR__"tiezhu",
]));

  setup();
}

