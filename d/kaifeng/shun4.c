//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "˴����");
  set ("long", @LONG

˴�����ϱ�˫��ͨ�У���������һ�����Ң���ֲ��У����������
�������ش����ֵ���һɫ��ʯ�����̳ɡ��ֵ������Ǹ��ָ����ĸ�լ
���̣�������һǮׯ��

LONG);

  set("exits", ([
        "north" : __DIR__"shun3",
        "south" : __DIR__"shun5",
        "west" : __DIR__"yangji",
      ]));

  set("outdoors", __DIR__);

  setup();
}


