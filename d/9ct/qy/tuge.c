// ������� ����� by Calvin

#include <ansi.h>
inherit ROOM;

void create ()
{
        set("short", YEL"�����"NOR);
  set ("long", @LONG

          ����������������������������������
          ����������������������������������
          ��������ɻ�ؽ��� ��Ը������Ե����
          ����������������������������������
          ����������������������������������

LONG);

  set("exits", ([
           "west" : __DIR__"lingge",
      ]));

  set("objects", ([
      "/d/9ct/npc/arl" : 1,
      ]));

  setup();
}
