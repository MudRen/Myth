//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ֻ��ǰ����ɽ��ֱ�����������Ǹ��հ���������Χ����Ҳ����
���ޱȣ�һ�ÿ÷·�������ӣ�ǰ����һ��ʯ�������飺
[33m
                      ��   ��   ɽ[m

LONG);

  set("exits", ([
        "eastdown"  : __DIR__"road5",
        "westup"  : __DIR__"shanlu2",
      ]));
  set("outdoors","yz");
  setup();
}
