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
  "south" : __DIR__"yangchang2",
  "northeast" : "/d/qujing/jisaiguo/pingxi",
]));

  setup();
}

