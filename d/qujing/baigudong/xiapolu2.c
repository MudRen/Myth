// room: /d/qujing/baigudong/xiashanlu1 
//create by smile 12/09/1998
inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

    ���ܾ����ĵģ�û��һ�������������ƺ����������ˣ�
û��һ˿�������������ġ�
    ·�Ը��ٲ��ƣ�Ұ�ݸ��һ�����������ϴ�������
����һ����
  
LONG);

  set("exits", ([
        "westdown"  : __DIR__"xiapolu3",
        "eastup"    : __DIR__"xiapolu1",
      ]));

  set("outdoors",__DIR__"");

  setup();
}
