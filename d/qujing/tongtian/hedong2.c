// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�Ӷ�");
  set ("long", @LONG

һ���ܿ�Ĵ�Ӻ�����ǰ��һ����ȥ��ԶԶ���Լ�����Լ�Ķ�
�����ӵ̵ı�����ǳ¼�ׯ�������ѽ��˺���һ�����żȻ
����һЩ�������ڱ��ϡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"hedong1",
        "west" : __DIR__"bing2", 
        "south"   : __DIR__"hedong3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



