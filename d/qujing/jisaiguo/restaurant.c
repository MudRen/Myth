#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������Ʈ�Ź�ŨŨ�Ŀ�����ζ�������������������˶���ϯ��
��������ǰ�Ŀ�¯�Ϸ��Ų�ͬ���࣬�������������ʳ�����е�
���˶��Ǵ�ںȾƣ���ڳ��⣬�Ե����ֵ����ӡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
"/obj/boss/jisaiguo_samui" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"centermarket",
]));

  setup();
}

