//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road1.c

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

���������ɫ��õ�������࣬������ţ�ֻ��һ���������
ֱͨԶ����������ͷ������û�з������ޣ�û�����㸡�ݣ�ֻ��
�Լ��ĽŲ���������������������������
LONG);

  set("exits", ([
        "east"  : __DIR__"road1",
        "west"  : __DIR__"road3",
      ]));
  set("outdoors","yz");
  setup();
}
