#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���¾�¥");
  set ("long", @LONG

����������������Ͼ�¥��,����ľ���Ʈ����
���������õ�ʵ����û��˵��.���й�������
���һʮ����,���3��...��¥��ľƾ�˵�Ǵ�
��Զ�ı���������� ... ...
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "east" : "/d/calvin/lanling/jie8",
       "up" : "/d/calvin/lanling/xingyuejiulou2",    
]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/obj/����/������" : 1,
        ]));

  setup();
}
