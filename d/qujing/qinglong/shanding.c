// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

վ��ɽ��������ɽ����һ���޼ʵ���ɫɭ�������������һ��
������������ɽ���Ϸ����࣬���ܵ�Ұ�޺�����ƺ����ӽ�
��һЩ�ˡ�

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shantou",
        "northeast"   : __DIR__"dongkou",
      ]));
  set("outdoors", __DIR__);

  setup();
}



