// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��ͬ��");
  set ("long", @LONG

��ͬ��Ϊ���������ľۼ��أ�Զ�������Ŀ����ܵ������������
����Ϣ��������ͬ�����ʰ�����������ˣ�����ר�ŵ��˷�ӭ�Ӱ�
��ס�޷�ʳ��

LONG);

  set("exits", ([ 
    "east" : __DIR__"chu",
    "south" : __DIR__"xiang",
    "north" : __DIR__"tian2",
  ]));
  set("valid_startroom", 1);
  setup();
}
