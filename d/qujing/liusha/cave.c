//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ�������Ƶ��ප�����ڵ�ˮ��Ȼ�Ǻ�ɫ�ģ�����Ѫ��࣬
���׵����澹Ȼ��һ�ѶѰ׹ǣ��еĻ�����Ѫ�⡣�����������һ
���췢������������������������һ��δ�Ծ�����ͷ��

LONG);
  set("exits", ([
        "out": __DIR__"dongkou",
        "up": __DIR__"riverside",
        ]));
  set("objects", ([
        __DIR__"npc/sha":1,
        ]));
  setup();
}
