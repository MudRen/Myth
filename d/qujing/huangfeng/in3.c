//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/in3.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��̨�Ϸ�������̫ʦ�Σ�����������Ƥ�������ġ����ӵ�ǰ�滹��
��һ��𣬻�������ɽ���ո�ͨ������������������Եĺ����
�棬��������С�����Ա߷�����������
LONG);
  set("exits", ([
        "south": __DIR__"in2",
      ]));
      set("objects",([
        __DIR__"npc/laoguai":1,
      ]));
  setup();
}

       
