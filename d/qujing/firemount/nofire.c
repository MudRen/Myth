// room: nofire

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set("outdoors", "firemount");
  set ("long", @LONG

����Ѿ����������ˣ��Ĵ���ð��һ˿˿�Ĳ��̡�

������ʱ����Ĵ�����Ӱ˰�����ܴ�ݲ�������˵����̫����
��������¯���ŷ�������¯ש���ڴ˴�������Ϊ����ɽ����һ�߽�
ȥ�ȳ��̻ң������ᶫ��������

����һ�ж���ƽ���ˣ������������̾���ѡ�

LONG);

    set("exits", ([
               "northwest" : __DIR__"shanwai",
               "eastdown"  : __DIR__"shanbian",
             ]));
setup();
}
