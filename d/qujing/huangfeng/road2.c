//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

·�ߵ�һ����Сé�����еĴ������£���Щé���Ա�һ�㶼��Щ������
һ������Ϳ��Ե����³������е���ǰ����Щ���Ƶ����⡣
LONG);

  set("exits", ([
        "west"  : __DIR__"road3",
        "east"  : __DIR__"road1",
      ]));
  set("outdoors","hfd");
  setup();
}
