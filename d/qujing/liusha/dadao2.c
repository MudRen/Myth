//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����ȥ����һ��������,·�����߲�ľïʢ,Ȫˮ����.����ķ��
�����������һ������,ż��һ��ֻҰ�ô�·�Դܹ�,����ֻ����
.�����ڴ����,��������Ŀ��,�����泩.

LONG);
  set("exits", ([
        "northeast"  : __DIR__"dadao1",
        "west":   __DIR__"dadao3",
        ]));
  set("outdoors","hfd");
  setup();
}
