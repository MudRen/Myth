#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���¥");
  set ("long", @LONG

һ��С�ɵĲ�¥��ÿ���Ƶ����գ����������������Ⱥ����ż��
Ҳ��������Ӽ������ʹ�ߡ��������ź���Ư���ĵ�̺������û
�����Σ����еĿ��˶����ڵ��¡�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/king" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yunqi",
]));
        set("no_fight", 1);
	set("no_magic", 1);
  setup();
}

