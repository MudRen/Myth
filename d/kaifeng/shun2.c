//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "˴����");
  set ("long", @LONG

˴�����ϱ�˫��ͨ�У���������һ�����Ң���ֲ��У����������
�������ش����ֵ���һɫ��ʯ�����̳ɡ��ֵ������Ǹ��ָ����ĸ�լ
���̣�������һ���š�

LONG);

  set("exits", ([
        "north" : __DIR__"shun1",
        "south" : __DIR__"shun3",
        "west" : __DIR__"yuxiang",
      ]));

  set("outdoors", __DIR__);

  setup();
}


