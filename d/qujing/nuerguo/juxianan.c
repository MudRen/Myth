// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/juxianan.c

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��������ɽ�������������Ǿ��ɡ���ν��С��ͨ��ˮ��é��
����ɽ�����ڷ�ˮ�Ͽɳ�֮Ϊ���ء��˿����Ž��ա���һ��
ʿ���������������ǰ����֮�ϣ���֪���ڴ�������������
ɹ̫����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"annei",
  "northdown" : __DIR__"jieyang",
]));

  create_door("enter","����","out",DOOR_CLOSED); 

  set("objects", ([
         __DIR__"npc/daoshi" : 1,
      ]));
  set("outdoors", __DIR__"");

  setup();
}






