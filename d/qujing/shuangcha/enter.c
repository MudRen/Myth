//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu5.c

inherit ROOM;

void create ()
{
  set ("short", "��ǰ");
  set ("long", @LONG

��ׯǰ�Ǽ��Ų����ľ����Ҷ������ĺڵ���ɫ���·���������
�ػ��Ŵ�ׯ������һЩҰ�����������棬һ���װ��ź���ǰ��
��Ȼ��û�ж���ˮ��
LONG);

  set("exits", ([
        "eastup" : __DIR__"shanlu5",
        "west"   : __DIR__"gate",
        "southwest" : "/d/qujing/yingjian/xiaolu1",
      ]));
  set("outdoors","sc");
  setup();
}
