#include <room.h>
inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
�����˲ι����ϡ�֦Ҷ������գ�һ��һ��Ľ������Ҷ����˸��
��ϸ������ԭ������һ����С���ӵĹ��ӣ���ص����������˲ι���
LONG);
      set("exits",([ /* sizeof() == 1 */
          "down"  : __DIR__"ground",
      ]));
      set("objects", ([
            "/d/obj/drug/renshenguo-fake"   : 1,
      ]));
      setup();
}

