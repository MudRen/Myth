//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

�����ģ����߳���ɽ�֣�����������С·�ϣ���ķ羰��ȫ��ɽ��
��һ����·�ߵ������������������ţ����涼��Щ�ײ�һ����߲�
��ɢ�����߲����е����¡�
LONG);

  set("exits", ([
        "west"  : __DIR__"road2",
        "eastup"  : "/d/qujing/yunzhan/shanlu3",
      ]));
  set("outdoors","hfd");
  setup();
}
