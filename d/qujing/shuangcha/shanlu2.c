//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu2.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�ߵ����㷢������ط�ԭ���Ǹ�Сɽ���ѹ��������е������
ǰ��ľ���Ҳ���Ǻ����������������ԼԼ����һ���˼ҵ���
�ӣ���ʱ������������Ұ��������������
LONG);

  set("exits", ([
        "eastdown" : __DIR__"shanlu1",
        "westup"   : __DIR__"shanlu3",
      ]));
  set("outdoors","sc");
  setup();
}
