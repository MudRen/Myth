//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�߽������㷢�ּ���ģ������Ĵ��֣�
[32m
                    �СССССССС�
                    ��  [1;37m��  ջ  ��[0;32m  ��
                    �СССССССС� 
LONG);

  set("exits", ([
        "north"  : __DIR__"in2",
        "up"  : __DIR__"shanlu3",
      ]));
  setup();
}
