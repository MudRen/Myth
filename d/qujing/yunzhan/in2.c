//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�ߵ��⣬��;��ö����ر�����ң����϶���Щ���ɲ�������
�ݣ�����Щɧ��ζ������������һ���ƴ�����ǰ�棬��������
���ر�ĵͰ������ͷһ��С�ľ�ײ�����������ʯͷ��
LONG);

  set("exits", ([
        "south"  : __DIR__"in1",
         "west"  : __DIR__"piandong",
        "east"  : __DIR__"xiaolu1",
        "north" : __DIR__"bed",
      ]));
  setup();
}
