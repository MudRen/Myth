// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����������࣬·�淭��һ�£�������ʯ��Ƕ���̾͡�������
�Ź�������ɢ���ŵ������������Ǹ�Ϊ���ֵ����У�������Ǭ
������

LONG);

  set("exits", ([
        "north"    : __DIR__"qiankun",
        "south"    : __DIR__"zhongshi",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

