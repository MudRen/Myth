//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "˴����");
  set ("long", @LONG

˴�����ϱ�˫��ͨ�У���������һ�����Ң���ֲ��У����������
�������ش����ֵ���һɫ��ʯ�����̳ɡ��ֵ������Ǹ��ָ����ĸ�լ
���̣�������һ���ƣ���������ջ����

LONG);

  set("exits", ([
        "southeast" : __DIR__"tieta",
        "north" : __DIR__"shun4",
        "west" : __DIR__"chunchun",
      ]));

  set("outdoors", __DIR__);

  setup();
}


