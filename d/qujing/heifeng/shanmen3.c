//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shanmen.c

inherit ROOM;

void create ()
{
  set ("short", "��ɽ��");
  set ("long", @LONG

�ߵ��������������ǰ����һ���Ʒ����Ʒ����ð�ɫʯͷ�������ɣ�
ʮ�ֵ���׳��ǰ���ǵ���ɽ����Ժ��ɽ����
LONG);

  set("exits", ([
        "westup"  : __DIR__"shandao",
        "east"  : __DIR__"shanlu4",
        "southeast" : __DIR__"road1",
      ]));
  set("outdoors","hf");
  setup();

}
