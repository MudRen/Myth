//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�Ի��˼����궼�ǳ��⣬���Գ������浽���ҵĶ�����õ��⣬
���˶����ѩ��ɽ���Ի��˼Ҿ��ǿ���Щ���⡢��˹����ġ�

LONG);

  set("exits", ([
        "south" : __DIR__"yard",
      ]));
  set("objects",([
        __DIR__"obj/rou" : 3,
        ]));
  setup();

}
