// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ·��Ϊ����ն���������һ��ͻأ����ʯ�ڶ��ͣ�Զ��
���͵ĺ����϶������ش���������Ұ�ַ紵�ݶ�������ë���
Ȼ�����������˽Ų���

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanlu2",
        "eastdown"   : __DIR__"shanlu5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



