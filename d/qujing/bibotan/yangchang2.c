#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��С·");
  set ("long", @LONG

С·��խ��ֻ����һ�˲�����С�·�߾���������һ��С�ľͻ�
�����Ϲҳ��˿ڡ����������к�ɫҰ����������ժ����Զ������
һ���ǳأ��ϱ���ȥ����ʯͷɽ��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yangchang1",
  "north" : __DIR__"yangchang3",
]));

  setup();
}

