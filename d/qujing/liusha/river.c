//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "��ɳ��");
  set ("long", @LONG

��Ȼһ����ӵ�ס�˳�·����ˮ���粻�壬������ӿ��һ����ȥ
�����ޱ߼ʣ���ˮ��ͣ�Ĵ������У��е����о�Ȼ��Բ��Ķ����
˵���ˣ�������ɽ��Ҳ�ܱ����ȥ���㲻��˫�ȷ��������ľ���
�����ڿ���

LONG);
  set("exits", ([
        "east"  : __DIR__"kuangye2",
        "westup":   __DIR__"riverside",
        ]));
  set("outdoors","hfd");
  setup();
}
