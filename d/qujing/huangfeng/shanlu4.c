//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

·����ЩҰ�޶��ǳ�˫�ɶԵĳ�����һ���۾�˸˸�Ź⣬һ��
��֪�����ɽ���������Ϊ�����١�
LONG);

  set("exits", ([
        "westup"  : __DIR__"dongkou",
        "eastdown"  : __DIR__"shanlu3",
      ]));
  set("outdoors","hfd");
  setup();
}
