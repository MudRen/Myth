//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�ߵ����㷢��·�Ѿ���ú������ˣ�������ճ���������������
���������·���ѱ棬ʮ�������ߴ��򣬶�������֮������һ
�߲�����ߵ��Ӳ�һ����ǰ���š�
LONG);

  set("exits", ([
        "eastdown" : "/d/westway/jiayu",
        "westup"   :    __DIR__"shanlu2",
      ]));
  set("outdoors","sc");

}
