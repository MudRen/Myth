// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

��԰����һ��С����С�������ǻ��ԣ�����ĵ����ҩ������÷
�ջ��ȵȡ����Եĺ����ǹ�ʵ���۵����ڹ�԰����������ͨ��
���

LONG);

  set("exits", ([
        "north"   : __DIR__"huayuan2",
        "west"   : __DIR__"zheng",
        "east"   : __DIR__"xiaolu",
      ]));
  set("outdoors", __DIR__);

  setup();
}



