//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

��������˰׹ǣ��㲻�����˸����䣬����ϸһ�ƣ�ԭ����Щ����
�Ĺ�ͷ��������ǿ�и���ǿ���֣�����֮����Ȼ�ֲ�������ֵ�һ
�ҡ�
LONG);

  set("exits", ([
        "east"  : __DIR__"in2",
      ]));
  set("objects",([
        __DIR__"obj/weed":1,
        ]));
  setup();
}
