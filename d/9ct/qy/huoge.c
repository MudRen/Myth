// ������� ����� by Calvin

#include <ansi.h>
inherit ROOM;

void create ()
{
      set("short", "�����");
  set ("long", @LONG

          ����������������������������������
          ����������������������������������
          ������������ɷ��  ��ԯ��޽޽���ס�
          ����������������������������������
          ����������������������������������

LONG);

  set("exits", ([
           "east" : __DIR__"lingge",
      ]));

  set("objects", ([
      "/d/9ct/npc/mkqy" : 1,
      ]));

  setup();
}
