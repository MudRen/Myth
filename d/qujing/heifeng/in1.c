//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ֵ���һ������ס�ĵط���Ȼ����˵����࣬һ����Ʒ
���Ǵ������ȣ�����Щ�ɶ����ض������Ǻ����ޱߴ�������
LONG);

  set("exits", ([
        "south"  : __DIR__"in2",
        "out"  : __DIR__"dongkou",
      ]));
  set("objects",([
        __DIR__"npc/yaojing":2,
        ]));
  setup();
}
