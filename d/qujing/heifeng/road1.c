//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

��һ����ɽ·�Ͼ���Щ���ӣ���һ������Ҷ�������죬·�ϵ���
����Щ���µ���Ҷ��
LONG);

  set("exits", ([
        "northwest"  : __DIR__"shanmen3",
        "south"      : __DIR__"road2",
      ]));
  set("outdoors","hf");
  setup();

}
