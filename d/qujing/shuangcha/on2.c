//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/on2.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�ݺ����Ļζ��ţ������ֲ������澭�������һЩ���ޣ���ʱ
�������ˣ�ֻ��һЩС�����ӵ�������
LONG);

  set("exits", ([
        "east" : __DIR__"on",
        "westdown" : __DIR__"shanlu4",
      ]));
  set("outdoors","sc");
  set("objects", ([
        __DIR__"npc/tiger": 1,
        ]));
  setup();
}
