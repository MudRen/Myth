//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

ľ�ŵĵ�Ӱӡ����ˮ�У��Եø�λ����������ׯȫ�����Ƿ�
��ǽ�ڣ������ۣ�תҲ���ıȽ�Χ����һ��������׳������
�������尲��

LONG);
  set("exits", ([
        "northwest" : "/d/qujing/sanda/shanlu2",
         "enter": __DIR__"house",
        "southeast"  : __DIR__"cunkou",
          ]));
  set("outdoors","cz");
  setup();
}
