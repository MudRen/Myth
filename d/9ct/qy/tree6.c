// ������ ��ϼ�� by Calvin

#include <ansi.h>
inherit "/d/9ct/qy/tree.c";

void falldown(object,object);
void create()
{
        set("short", HIR"���ء���ϼ��"NOR);
  set ("long", @LONG

          ����������������������������������
          ����������������������������������
          ��������ϼ����Ϧ  ͤ��С���������
          ����������������������������������
          ����������������������������������

LONG);

        set("exits", ([
  "down": __DIR__"liu",
        ]));

        set("objects", ([
              "/d/9ct/obj/niang.c" : 1,
              ]));

        setup();
}
