//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ı��Ϲ���Щǿ��Ӳ�󣬲��ż����������ڹ����ϴ���
����Ѫ�ȵĻ�Ƥ��ǽ��ͷ�������ǹ����������м������
�ŵ��ӡ�

LONG);

  set("exits", ([
        "east" : __DIR__"yard",
      ]));
  set("objects", ([
        __DIR__"npc/liumm": 1,
        ]));
  setup();

}
