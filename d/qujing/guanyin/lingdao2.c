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
        "southup" : __DIR__"lingdao3",
        "northdown"  : __DIR__"lingdao1",
      ]));

  set("outdoors", __DIR__);

  setup();
}

