// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ����������Ժǽ�ߴ���ɽʯ���ɡ����߿�ǽ����һ��������
��ǰ����һƬ�յأ�������֮�á���������ͨ��λ���ӵĸ�
¥���ϱ���������

LONG);

  set("exits", ([
        "north"   : __DIR__"fumen",
        "south"   : __DIR__"zheng",
        "east"   : __DIR__"da",
      ]));
  set("outdoors", __DIR__);

  setup();
}



