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
        "east" : "/d/lanling/jie8",
]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

  setup();
}

