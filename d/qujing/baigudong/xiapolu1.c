// room: /d/qujing/baigudong/xiashanlu1 
//create by smile 12/09/1998
inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

    ���ܾ����ĵģ�û��һ�������������ƺ����������ˣ�
û��һ˿�������������ġ� ·�Ը��ٲ��ƣ�Ұ�ݸ��
  
LONG);

  set("exits", ([
        "westdown"  : __DIR__"xiapolu2",
        "eastup"    : __DIR__"shanshipo",
      ]));

  set("outdoors",__DIR__"");

  setup();
}
