//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;
#include "jiandi.h"

void create ()
{
  set ("short", "[1m����[m");
  set ("long", @LONG

���׵�������Щˮ�ݣ�����ЩСϺ�ף����������ȥ��ż�����ܿ���
һ���ߺ��ǣ��������ǰ�����ʣ�Ĺ�ͷ��

LONG);

  set("exits", ([
        "north" : __DIR__"jiandi4",
        "west"  : __DIR__"jiandi2",
      ]));
   set("objects", ([
        "/d/jz/obj/fish": 3,
        ]));
  setup();

}
