// created by angell 1/1/2001
// room: /d/qujing/huangfeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

һ��С·���ּ�������ȥ��·�������ƽ�������С�·�Ϻ���
�������ˣ�ż��������ֻ�д��͵��̶ӡ�ǰ��·�����۴��ݲ�
���˿����ӣ������ƺ�д������(zi)��

LONG);

  set("item_desc",([
    "zi" : "����д�ţ�"+
    "ɽ���л���������������������֮��\n",
  ]));

  set("exits", ([
        "northeast" : __DIR__"guanwai",
        "westup"      : __DIR__"shanlu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}
    
