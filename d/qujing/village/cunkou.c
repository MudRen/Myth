//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

��̧ͷԶ��һ�����������м��䷿�ᣬ��ʵ������������

        �Ŵ���أ�լ����ɽ��������ȽȽ��
        ������߰ߣ����Ұ��ӭ˪�ޡ�

LONG);
  set("exits", ([
        "northwest"  : __DIR__"road4",
        "east"  : __DIR__"road3",
        "north" : __DIR__"huanglu1",
      //  "southwest": "/d/
          ]));
  set("outdoors","cz");
  setup();
}
