// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

��԰����һ��С����С�������ǻ��ԣ�����ĵ����ҩ������÷
�ջ��ȵȡ����Եĺ����ǹ�ʵ���۵����ڹ�԰���ϱ�����ͨ��
���

LONG);

  set("exits", ([
        "east"   : __DIR__"huayuan2",
        "south"   : __DIR__"zheng",
      ]));
  set("outdoors", __DIR__);

  setup();
}



