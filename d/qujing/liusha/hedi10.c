//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include "hedi.h"

void create ()
{
  set ("short", "�ӵ�");
  set ("long", @LONG

���������������������˻��ţ����γ���һ���޴�����У���
���˺ӵ�������ƺ�Ȼ��ȴ�ž�����������Ҳվ��ס�ˣ���
�紵�ɻ���ҡ�ڲ�������ʱ���п��ܱ����о��ߡ�

LONG);
  set("exits", ([
        "east":   __DIR__"hedi7",
        "northwest":   __DIR__"hedi11",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}
