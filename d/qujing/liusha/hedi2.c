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

���ܻ������һƬ����ˮ���䳹�ǣ���о�ȫ������ľ����
�Ž�������ʹ�����ķ·�û�������������������ܾ��ŵÿ��£�
������о������ܰ������޾������ա�

LONG);
  set("exits", ([
        "west" :   __DIR__"hedi4",
        "north":   __DIR__"hedi1",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}
