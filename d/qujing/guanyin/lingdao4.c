inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����������ǧ�¾��㡣�����˲��������������㡣ɽ�ݷ���
Ұ�����������ͱڣ�޵����������ƽ�ڡ�����˫������ʯ��
ҰԳ�����Ǹ��÷�⡣
LONG);
 
  set("exits", ([
        "southup" : __DIR__"lingdao5",
        "north"  : __DIR__"fangcaopo",
      ]));

  set("outdoors", __DIR__);

  setup();
}

