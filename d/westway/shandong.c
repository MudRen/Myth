// create by snowcat.c 4/8/1997
// room: /d/westway/shandong.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ����");
  set ("long", @LONG

ɽ�����е�谵���Ӷ��ⶥ�ϴ���һЩ���������ڱ��ϳ���һ
������̦��������ǵ�������һЩ�ɲݡ�������������һλ
���ˣ��ƺ���û�в����ĵ�����

LONG);

  set("exits", ([
        "out"      : __DIR__"yunti",
      ]));

  set("objects",([
        __DIR__"npc/laoren" : 1,
       ]));

  setup();
}





