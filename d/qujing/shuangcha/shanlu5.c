//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu5.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

����ɽ���£���������һ��ɽׯ��ׯ԰���󣬾����۵ף�һ��
С������ɽ��������ׯ����ǵ��ؿ��Կ�����һЩ������
æ����ʲô��
LONG);

  set("exits", ([
        "eastup" : __DIR__"shanlu4",
        "westdown"   : __DIR__"enter",
      ]));
  set("outdoors","sc");

}
