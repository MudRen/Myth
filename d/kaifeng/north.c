//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

#include "guanli.h"

void create ()
{
  set ("short", "������̨");
  set ("long", @LONG

����̨��ƽ̹���ʵĺ�ľһ������ɣ��������Ż��ƻ�Ƥ�ͽ�
Ǯ��Ƥ��̨�Ϸ���һ�����ɺ�����̫ʦ�Σ������ù���ǱȽ�
���ʵعۿ�������

LONG);

  set("exits", ([
        "north"   : __DIR__"gate",
        "west"   : __DIR__"spring",
        "east"   : __DIR__"summer",
//        "southdown"   : __DIR__"ground",
      ]));

  set("objects", ([
        __DIR__"npc/siguan"  : 2,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (wizardp(who))
    return ::valid_leave(who, dir);
  if (dir == "southdown")
    //return notify_fail ("�Բ������������Դ���������\n");
    return can_enter (who);
  return ::valid_leave(who, dir);
}


